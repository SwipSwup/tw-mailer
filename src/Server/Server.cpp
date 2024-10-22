//
// Created by david on 22/10/2024.
//

#include "Server.h"
#include <iostream>
#include <cstring>
#include <sstream>
#include <filesystem>

namespace fs = std::filesystem;

namespace TW_Mailer
{
    bool Server::isRunning = true;
    int Server::server_socket;
    //std::vector<std::thread> Server::clientThreads;

    Server::Server(int port, const std::string &mailSpoolDir) : mailSpoolDir(mailSpoolDir)
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

        // Ensure the mail-spool directory exists
        if (!fs::exists(mailSpoolDir))
        {
            fs::create_directories(mailSpoolDir);
        }
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
        std::string message;
        do
        {
            message = receiveMessage(client_socket);
            if (message.empty())
            {
                break;
            }

            std::cout << "Command received: " << message << std::endl;
            processMessage(client_socket, message);

        } while (isRunning && message != "QUIT\n");

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

    void Server::processMessage(int client_socket, const std::string &command)
    {
        std::istringstream iss(command);
        std::string cmd;
        iss >> cmd;

        switch(cmd.c_str()) {
            case "SEND":

        }

        if (cmd == "SEND")
        {
            std::string sender;
            iss >> sender;
            if (validateUsername(sender))
            {
                sendMail(client_socket, sender);
                sendMessage(client_socket, "Yuhu");
            }
            else
            {
                sendMessage(client_socket, "ERR\n");
            }
        }
        else if (cmd == "LIST")
        {
            std::string username;
            iss >> username;
            listMessages(client_socket, username);
        }
        else if (cmd == "READ")
        {
            std::string username;
            int messageNumber;
            iss >> username >> messageNumber;
            readMessage(client_socket, username, messageNumber);
        }
        else if (cmd == "DEL")
        {
            std::string username;
            int messageNumber;
            iss >> username >> messageNumber;
            deleteMessage(client_socket, username, messageNumber);
        }
        else if (cmd == "QUIT")
        {
            sendMessage(client_socket, "OK\n");
        }
        else
        {
            sendMessage(client_socket, "ERR\n");
        }
    }

    void Server::sendMail(int client_socket, const std::string &sender)
    {
        // Implementation of SEND command
    }

    void Server::listMessages(int client_socket, const std::string &username)
    {
        // Implementation of LIST command
    }

    void Server::readMessage(int client_socket, const std::string &username, int messageNumber)
    {
        // Implementation of READ command
    }

    void Server::deleteMessage(int client_socket, const std::string &username, int messageNumber)
    {
        // Implementation of DEL command
    }

    bool Server::validateUsername(const std::string &username)
    {
        return username.length() <= 8 && std::all_of(username.begin(), username.end(), [](char c)
        {
            return std::isalnum(c);
        });
    }

    std::string Server::getUserInboxPath(const std::string &username)
    {
        return mailSpoolDir + "/" + username + "_inbox";
    }

    std::string Server::receiveMessage(int client_socket)
    {
        char buffer[BUF];
        int size = recv(client_socket, buffer, BUF - 1, 0);
        if (size == -1)
        {
            perror("Receive error");
            return "";
        }

        if (size == 0)
        {
            std::cout << "Client closed remote socket" << std::endl;
            return "";
        }

        buffer[size] = '\0';
        return std::string(buffer);
    }

    void Server::sendMessage(int client_socket, const std::string &message)
    {
        if (send(client_socket, message.c_str(), message.size(), 0) == -1)
        {
            perror("Send error");
        }
    }
} // TW_Mailer