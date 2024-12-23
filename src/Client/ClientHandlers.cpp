#include "ClientHandlers.h"
#include <iostream>
#include <sstream>

namespace TW_Mailer
{
    Message ClientHandlers::handleLogin()
    {
        Message message {LOGIN};
        std::string str;

        std::cout << "Enter username: ";
        std::getline(std::cin, str);
        message.parameters["username"] = str;

        std::cout << "Enter password: ";
        std::getline(std::cin, str);
        message.parameters["password"] = str;

        return message;
    }

    //Ask the user all the information and build the message
    Message ClientHandlers::handleSend()
    {
        Message message {SEND};
        std::string str;

        std::cout << "Enter receiver username: ";
        std::getline(std::cin, str);
        message.parameters["receiver"] = str;

        std::cout << "Enter subject (max 80 chars): ";
        std::getline(std::cin, str);
        message.parameters["subject"] = str;

        std::cout << "Enter body (end with a single dot on a line):" << std::endl;
        std::ostringstream stream;
        std::string line;
        while (std::getline(std::cin, line) && line != ".")
        {
            stream << line << "\n";
        }
        message.body = stream.str();

        return message;
    }

    Message ClientHandlers::handleList()
    {
        Message message {LIST};

        return message;
    }

    Message ClientHandlers::handleRead()
    {
        Message message {READ};
        std::string messageNumber;

        std::cout << "Enter message number: ";
        std::getline(std::cin, messageNumber);
        message.parameters["messageNumber"] = messageNumber;

        return message;
    }

    Message ClientHandlers::handleDel()
    {
        Message message {DEL};
        std::string messageNumber;

        std::cout << "Enter message number: ";
        std::getline(std::cin, messageNumber);
        message.parameters["messageNumber"] = messageNumber;

        return message;
    }

    Message ClientHandlers::handleQuit()
    {
        std::cout << "Disconnected from server." << std::endl;
        return Message{QUIT};
    }
} // TW_Mailer