//
// Created by david on 22/10/2024.
//
#include "Client.h"
#include <iostream>
#include <cstring>
#include <sstream>

namespace TW_Mailer
{
    Client::Client(const std::string& server_ip, int server_port) {
        client_socket = socket(AF_INET, SOCK_STREAM, 0);
        if (client_socket == -1) {
            perror("Socket creation error");
            exit(EXIT_FAILURE);
        }

        memset(&server_address, 0, sizeof(server_address));
        server_address.sin_family = AF_INET;
        server_address.sin_port = htons(server_port);

        if (inet_pton(AF_INET, server_ip.c_str(), &server_address.sin_addr) <= 0) {
            perror("Invalid server IP address");
            exit(EXIT_FAILURE);
        }
    }

    Client::~Client() {
        if (shutdown(client_socket, SHUT_RDWR) == -1) {
            perror("Shutdown client socket");
        }
        if (close(client_socket) == -1) {
            perror("Close client socket");
        }
    }

    bool Client::connectToServer() {
        if (connect(client_socket, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
            perror("Connection error");
            return false;
        }
        std::cout << "Connected to server." << std::endl;
        return true;
    }

    void Client::run() {
        std::string command;
        while (true) {
            std::cout << "Enter command (SEND, LIST, READ, DEL, QUIT): ";
            std::getline(std::cin, command);

            if (command == "SEND") {
                sendMail();
            } else if (command == "LIST") {
                listMessages();
            } else if (command == "READ") {
                readMessage();
            } else if (command == "DEL") {
                deleteMessage();
            } else if (command == "QUIT") {
                sendCommand("QUIT\n");
                std::cout << "Disconnected from server." << std::endl;
                break;
            } else {
                std::cout << "Invalid command." << std::endl;
            }
        }
    }

    void Client::sendCommand(const std::string& command) {
        if (send(client_socket, command.c_str(), command.size(), 0) == -1) {
            perror("Send error");
        }
    }

    std::string Client::receiveResponse() {
        char buffer[BUF];
        int size = recv(client_socket, buffer, BUF - 1, 0);
        if (size == -1) {
            perror("Receive error");
            return "";
        }

        if (size == 0) {
            std::cout << "Server closed connection" << std::endl;
            return "";
        }

        buffer[size] = '\0';
        return std::string(buffer);
    }

    void Client::sendMail() {
        std::string sender, receiver, subject, message;

        std::cout << "Enter sender username (max 8 chars): ";
        std::getline(std::cin, sender);

        std::cout << "Enter receiver username (max 8 chars): ";
        std::getline(std::cin, receiver);

        std::cout << "Enter subject (max 80 chars): ";
        std::getline(std::cin, subject);

        std::cout << "Enter message (end with a single dot on a line):" << std::endl;
        std::ostringstream msgStream;
        std::string line;
        while (std::getline(std::cin, line) && line != ".") {
            msgStream << line << "\n";
        }
        message = msgStream.str();

        // Form the SEND command
        std::ostringstream command;
        command << "SEND\n" << sender << "\n" << receiver << "\n" << subject << "\n" << message << ".\n";

        sendCommand(command.str());

        std::string response = receiveResponse();
        std::cout << "Server response: " << response << std::endl;
    }

    void Client::listMessages() {
        std::string username;

        std::cout << "Enter username: ";
        std::getline(std::cin, username);

        // Form the LIST command
        std::ostringstream command;
        command << "LIST\n" << username << "\n";

        sendCommand(command.str());

        std::string response = receiveResponse();
        std::cout << "Server response:\n" << response << std::endl;
    }

    void Client::readMessage() {
        std::string username;
        int messageNumber;

        std::cout << "Enter username: ";
        std::getline(std::cin, username);

        std::cout << "Enter message number: ";
        std::cin >> messageNumber;
        std::cin.ignore();  // Clear newline from input buffer

        // Form the READ command
        std::ostringstream command;
        command << "READ\n" << username << "\n" << messageNumber << "\n";

        sendCommand(command.str());

        std::string response = receiveResponse();
        std::cout << "Server response:\n" << response << std::endl;
    }

    void Client::deleteMessage() {
        std::string username;
        int messageNumber;

        std::cout << "Enter username: ";
        std::getline(std::cin, username);

        std::cout << "Enter message number: ";
        std::cin >> messageNumber;
        std::cin.ignore();  // Clear newline from input buffer

        // Form the DEL command
        std::ostringstream command;
        command << "DEL\n" << username << "\n" << messageNumber << "\n";

        sendCommand(command.str());

        std::string response = receiveResponse();
        std::cout << "Server response:\n" << response << std::endl;
    }
} // TW_Mailer