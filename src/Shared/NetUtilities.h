#ifndef TW_MAILER_NETUTILITIES_H
#define TW_MAILER_NETUTILITIES_H

#include <string>

#define BUF 1024

namespace TW_Mailer
{

    class NetUtilities
    {
    public:
        static void sendMessageStr(int socket, const std::string& message);
        static std::string receiveMessageStr(int socket);
    };

} // TW_Mailer

#endif //TW_MAILER_NETUTILITIES_H
