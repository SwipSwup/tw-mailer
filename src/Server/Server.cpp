#include "Server.h"
#include "ServerHandler.h"
#include "../Shared/NetUtilities.h"
#include "MailManager/MailManager.h"
#include <iostream>
#include <cstring>

namespace TW_Mailer
{
    bool Server::isRunning = true;
    int Server::server_socket;
    MailManager* Server::mailManager;

    Server::Server(int port, const std::string &mailDir)
    {
        server_socket = socket(AF_INET, SOCK_STREAM, 0);
        if (server_socket == -1)
        {
            perror("Socket creation error");
            exit(EXIT_FAILURE);
        }

        int reuseValue = 1;
        setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &reuseValue, sizeof(reuseValue));

        memset(&server_address, 0, sizeof(server_address));
        server_address.sin_family = AF_INET;
        server_address.sin_addr.s_addr = INADDR_ANY;
        server_address.sin_port = htons(port);

        signal(SIGINT, signalHandler);

        setupCommandHandlers();

        mailManager = new MailManager(mailDir);
    }

    Server::~Server()
    {
        if (isRunning)
        {
            if (shutdown(server_socket, SHUT_RDWR) == -1)
            {
                perror("Shutdown server socket");
            }
            if (close(server_socket) == -1)
            {
                perror("Close server socket");
            }
        }

        for (auto &t: clientThreads)
        {
            if (t.joinable())
            {
                t.join();
            }
        }
    }

    void Server::setupCommandHandlers()
    {
        commandHandler[SEND] = ServerHandler::handleSend;
        commandHandler[LIST] = ServerHandler::handleList;
        commandHandler[READ] = ServerHandler::handleRead;
        commandHandler[DEL] = ServerHandler::handleDel;
        commandHandler[QUIT] = ServerHandler::handleQuit;
    }

    void Server::signalHandler(int signum)
    {
        std::cout << "\nServer shutting down...\n";
        isRunning = false;
        if (shutdown(server_socket, SHUT_RDWR) == -1)
        {
            perror("Shutdown server socket");
        }
        if (close(server_socket) == -1)
        {
            perror("Close server socket");
        }
        exit(signum);
    }

    bool Server::start()
    {
        if (bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address)) == -1)
        {
            perror("Bind error");
            return false;
        }

        if (listen(server_socket, 5) == -1)
        {
            perror("Listen error");
            return false;
        }

        std::cout << "Server started, waiting for connections..." << std::endl;
        return true;
    }

    void Server::run()
    {
        while (isRunning)
        {
            struct sockaddr_in client_address;
            socklen_t addr_len = sizeof(client_address);
            int client_socket = accept(server_socket, (struct sockaddr*) &client_address, &addr_len);

            if (client_socket == -1)
            {
                if (isRunning)
                {
                    perror("Accept error");
                }
                continue;
            }

            std::cout << "Client connected from "
                      << inet_ntoa(client_address.sin_addr)
                      << ":" << ntohs(client_address.sin_port) << std::endl;

            clientThreads.push_back(std::thread(&Server::handleClient, this, client_socket));
        }
    }

    void Server::handleClient(int client_socket)
    {
        Message message;
        do
        {
            try
            {
                message = Message::parse(NetUtilities::receiveMessageStr(client_socket));

                if (!commandHandler.contains(message.command))
                {
                    NetUtilities::sendMessageStr(client_socket, Message{ERR, "Invalid Command"}.serialize());
                    return;
                }

                NetUtilities::sendMessageStr(client_socket, commandHandler[message.command](message).serialize());
            }
            catch (std::exception &e)
            {
                NetUtilities::sendMessageStr(client_socket, Message{ERR, e.what()}.serialize());
            }
            catch (ErrorCode &err)
            {
                NetUtilities::sendMessageStr(client_socket, createErrorMessage(err).serialize());
            }

        } while (isRunning && message.command != QUIT);

        if (shutdown(client_socket, SHUT_RDWR) == -1)
        {
            perror("Shutdown client socket");
        }
        if (close(client_socket) == -1)
        {
            perror("Close client socket");
        }

        std::cout << "Client disconnected" << std::endl;
    }

    Message Server::createErrorMessage(ErrorCode code)
    {
        std::string msg;

        switch (code)
        {
            case USER_NOT_FOUND:
                msg = "User not found";
                break;
            case INVALID_MAIL_INDEX:
                msg = "Mail index invalid";
                break;
            case PARSING_ERROR:
                msg = "Error while parsing message";
                break;
            default:
                msg = "Unknown server error";
        }

        return Message{ERR, msg};
    }
} // TW_Mailer