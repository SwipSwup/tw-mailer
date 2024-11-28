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
    class LdapHandler;
    class Client {
    public:
        Client(const std::string& server_ip, int server_port);
        ~Client();

        bool connectToServer();
        void run();

    private:
        int server_socket;
        std::string username;

        struct sockaddr_in server_address{};
        std::map<std::string, Message (*)()> commandHandler;

        void setupCommandHandlersPreLogin();
        void setupCommandHandlersPostLogin();

    };

} // TW_Mailer

#endif //TW_MAILER_CLIENT_H
