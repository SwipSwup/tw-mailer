#include "Client.h"
#include "../Shared/ErrorCode.h"
#include "ClientHandlers.h"
#include "../Shared/NetUtilities.h"
#include <iostream>
#include <cstring>

namespace TW_Mailer
{
    Client::Client(const std::string &server_ip, int server_port)
    {
        client_socket = socket(AF_INET, SOCK_STREAM, 0);
        if (client_socket == -1)
        {
            perror("Socket creation error");
            exit(EXIT_FAILURE);
        }

        memset(&server_address, 0, sizeof(server_address));
        server_address.sin_family = AF_INET;
        server_address.sin_port = htons(server_port);

        setupCommandHandlers();
        if (inet_pton(AF_INET, server_ip.c_str(), &server_address.sin_addr) <= 0)
        {
            perror("Invalid server IP address");
            exit(EXIT_FAILURE);
        }
    }

    Client::~Client()
    {
        if (shutdown(client_socket, SHUT_RDWR) == -1)
        {
            perror("Shutdown client socket");
        }
        if (close(client_socket) == -1)
        {
            perror("Close client socket");
        }
    }

    void Client::setupCommandHandlers()
    {
        commandHandler["SEND"] = ClientHandlers::handleSend;
        commandHandler["LIST"] = ClientHandlers::handleList;
        commandHandler["READ"] = ClientHandlers::handleRead;
        commandHandler["DEL"] = ClientHandlers::handleDel;
        commandHandler["QUIT"] = ClientHandlers::handleQuit;
    }

    bool Client::connectToServer()
    {
        if (connect(client_socket, (struct sockaddr*) &server_address, sizeof(server_address)) == -1)
        {
            perror("Connection error");
            return false;
        }
        std::cout << "Connected to server." << std::endl;
        return true;
    }

    void Client::run()
    {
        std::string command;
        do
        {
            std::cout << "Enter command (SEND, LIST, READ, DEL, QUIT): ";
            std::getline(std::cin, command);

            if (!commandHandler.contains(command))
            {
                std::cout << "Invalid command." << std::endl;
                continue;
            }

            NetUtilities::sendMessageStr(client_socket, commandHandler[command]().serialize());

            try {
                std::string msgStr = NetUtilities::receiveMessageStr(client_socket);

                if (msgStr.empty())
                {
                    break;
                }

                Message response = Message::parse(msgStr);

                if (response.command == ERR)
                {
                    std::cout << "Server error: " << response.body << std::endl;
                    continue;
                }

                //TODO suboptimal
                std::cout << response.body << std::endl;
            } catch (ErrorCode err) {
                if(err == PARSING_ERROR)
                    std::cout << "Error while parsing server response" << std::endl;
            }

        } while (command != "QUIT");
    }
} // TW_Mailer