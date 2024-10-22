#include <sys/socket.h>
#include <iostream>
#include "NetUtilities.h"


namespace TW_Mailer
{
    void NetUtilities::sendMessageStr(int socket, const std::string &message)
    {
        if (send(socket, message.c_str(), message.size(), 0) == -1)
        {
            perror("Send error");
        }
    }

    std::string NetUtilities::receiveMessageStr(int socket)
    {
        char buffer[BUF];
        int size = recv(socket, buffer, BUF - 1, 0);
        if (size == -1)
        {
            perror("Receive error");
            return "";
        }

        if (size == 0)
        {
            std::cout << "Closed connection" << std::endl;
            return "";
        }

        buffer[size] = '\0';
        return std::string(buffer);
    }
} // TW_Mailer