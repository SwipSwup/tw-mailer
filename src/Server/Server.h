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
#include "../Shared/Message.h"
#include "../Shared/ErrorCode.h"

namespace TW_Mailer
{
    class MailManager;
    class Server {
    public:
        Server(int port, const std::string& mailSpoolDir);
        ~Server();
        static MailManager* mailManager;
        static void signalHandler(int signum);

    private:
        static int server_socket;
        struct sockaddr_in server_address{};
        static bool isRunning;

        std::map<Command, Message (*)(Message)> commandHandler;
        void setupCommandHandlers();

    public:
        bool start();
        void run();

    private:
        void handleClient(int client_socket);
        std::vector<std::thread> clientThreads;

        Message createErrorMessage(ErrorCode code);
    };

} // TW_Mailer

#endif //TW_MAILER_SERVER_H
