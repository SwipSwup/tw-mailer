//
// Created by david on 22/10/2024.
//

#ifndef TW_MAILER_SERVER_H
#define TW_MAILER_SERVER_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string>
#include <thread>
#include <vector>
#include <map>
#include <csignal>

#define BUF 1024

namespace TW_Mailer
{
    class Server {
    public:
        Server(int port, const std::string& mailSpoolDir);
        ~Server();

        bool start();
        void run();
        static void signalHandler(int signum);

    private:
        static int server_socket;
        struct sockaddr_in server_address{};
        std::string mailSpoolDir;
        static bool isRunning;

        void handleClient(int client_socket);
        std::string receiveMessage(int client_socket);
        void sendMessage(int client_socket, const std::string& message);
        void processMessage(int client_socket, const std::string& command);

        // Helper functions
        void sendMail(int client_socket, const std::string& sender);
        void listMessages(int client_socket, const std::string& username);
        void readMessage(int client_socket, const std::string& username, int messageNumber);
        void deleteMessage(int client_socket, const std::string& username, int messageNumber);
        bool validateUsername(const std::string& username);
        std::string getUserInboxPath(const std::string& username);

        std::vector<std::thread> clientThreads;
    };

} // TW_Mailer

#endif //TW_MAILER_SERVER_H
