//
// Created by david on 22/10/2024.
//

#ifndef TW_MAILER_CLIENT_H
#define TW_MAILER_CLIENT_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string>

#define BUF 1024

namespace TW_Mailer
{
    class Client {
    public:
        Client(const std::string& server_ip, int server_port);
        ~Client();

        bool connectToServer();
        void run();

    private:
        int client_socket;
        struct sockaddr_in server_address;

        void sendCommand(const std::string& command);
        std::string receiveResponse();

        // Command handlers
        void sendMail();
        void listMessages();
        void readMessage();
        void deleteMessage();
    };

} // TW_Mailer

#endif //TW_MAILER_CLIENT_H
