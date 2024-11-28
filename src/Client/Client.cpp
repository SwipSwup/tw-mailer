#include "Client.h"
#include "../Shared/ErrorCode.h"
#include "ClientHandlers.h"
#include "../Shared/NetUtilities.h"
#include <iostream>
#include <ldap.h>

namespace TW_Mailer
{
    // Initialize client
    Client::Client(const std::string &server_ip, int server_port)
    {
        server_socket = socket(AF_INET, SOCK_STREAM, 0);
        if (server_socket == -1)
        {
            perror("Socket creation error");
            exit(EXIT_FAILURE);
        }

        memset(&server_address, 0, sizeof(server_address));
        server_address.sin_family = AF_INET;
        server_address.sin_port = htons(server_port);

        setupCommandHandlersPreLogin();
        if (inet_pton(AF_INET, server_ip.c_str(), &server_address.sin_addr) <= 0)
        {
            perror("Invalid server IP address");
            exit(EXIT_FAILURE);
        }
    }

    Client::~Client()
    {
        if (shutdown(server_socket, SHUT_RDWR) == -1)
        {
            perror("Shutdown client socket");
        }
        if (close(server_socket) == -1)
        {
            perror("Close client socket");
        }
    }

    void Client::setupCommandHandlersPreLogin()
    {
        // Setup all possible commands with their handles

        commandHandler["LOGIN"] = ClientHandlers::handleLogin;
        commandHandler["QUIT"] = ClientHandlers::handleQuit;
    }

    void Client::setupCommandHandlersPostLogin()
    {
        commandHandler.erase(commandHandler.find("LOGIN"));
        commandHandler["SEND"] = ClientHandlers::handleSend;
        commandHandler["LIST"] = ClientHandlers::handleList;
        commandHandler["READ"] = ClientHandlers::handleRead;
        commandHandler["DEL"] = ClientHandlers::handleDel;
    }


    bool Client::connectToServer()
    {
        //Tries to connect to the server
        if (connect(server_socket, (struct sockaddr*) &server_address, sizeof(server_address)) == -1)
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
            std::cout << "Enter command (LOGIN, QUIT): ";
            std::getline(std::cin, command);

            if (!commandHandler.contains(command))
            {
                std::cout << "Invalid command." << std::endl;
                continue;
            }

            if (command == "QUIT")
            {
                return;
            }

            Message ms = commandHandler[command]();

            NetUtilities::sendMessageStr(server_socket, ms.serialize());
            try
            {
                // Wait for the server response
                std::string msgStr = NetUtilities::receiveMessageStr(server_socket);

                if (msgStr.empty())
                {
                    break;
                }

                Message response = Message::parse(msgStr);

                // If the server returned an error print the error message to the user
                if (response.command == ERR)
                {
                    std::cout << "Server error: " << response.body << std::endl;
                    continue;
                }

                username = ms.parameters["username"];

            } catch (ErrorCode err)
            {
                //Catch the only Error code that the user can get
                if (err == PARSING_ERROR)
                    std::cout << "Error while parsing server response" << std::endl;
            }

        } while (username.empty());

        setupCommandHandlersPostLogin();

        do
        {
            std::cout << "Enter command (SEND, LIST, READ, DEL, QUIT): ";
            std::getline(std::cin, command);

            //Check if the command is registered
            if (!commandHandler.contains(command))
            {
                std::cout << "Invalid command." << std::endl;
                continue;
            }

            // Send the message to the server
            Message ms = commandHandler[command]();
            ms.parameters["uid"] = username;

            NetUtilities::sendMessageStr(server_socket, ms.serialize());

            try
            {
                // Wait for the server response
                std::string msgStr = NetUtilities::receiveMessageStr(server_socket);

                if (msgStr.empty())
                {
                    break;
                }

                Message response = Message::parse(msgStr);

                // If the server returned an error print the error message to the user
                if (response.command == ERR)
                {
                    std::cout << "Server error: " << response.body << std::endl;
                    continue;
                }

                //Print the message body
                std::cout << response.body << std::endl;
            } catch (ErrorCode err)
            {
                //Catch the only Error code that the user can get
                if (err == PARSING_ERROR)
                    std::cout << "Error while parsing server response" << std::endl;
            }

        } while (command != "QUIT");
    }
} // TW_Mailer