#ifndef TW_MAILER_CLIENT_H
#define TW_MAILER_CLIENT_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string>
#include "../Shared/Message.h"

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
        struct sockaddr_in server_address{};
        std::map<std::string, Message (*)()> commandHandler;

        void setupCommandHandlers();
    };

} // TW_Mailer

#endif //TW_MAILER_CLIENT_H
