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
#include <chrono>
#include <map>
#include <csignal>
#include <mutex>
#include "../Shared/Message.h"
#include "../Shared/ErrorCode.h"

#define MAX_LOGIN_ATTEMPTS 3
#define BLACKLIST_DURATION_SECONDS 60

namespace TW_Mailer
{
    struct BlacklistEntry
    {
        int invalidLoginAttempts = 0;
        std::chrono::time_point<std::chrono::system_clock, std::chrono::duration<long, std::ratio<1, 1000000000>>> timePoint;
    };

    class MailManager;

    class LdapHandler;

    class Server
    {
    public:
        Server(int port, const std::string &mailSpoolDir);

        ~Server();

        static MailManager* mailManager;

        static void signalHandler(int signum);

        static LdapHandler* ldapHandler;

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
        std::mutex mutex;
        std::map<int, BlacklistEntry> blacklist;

        Message createErrorMessage(ErrorCode code);
    };
} // TW_Mailer

#endif //TW_MAILER_SERVER_H
