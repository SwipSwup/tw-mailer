#ifndef TW_MAILER_CLIENTHANDLERS_H
#define TW_MAILER_CLIENTHANDLERS_H

#include "../Shared/Message.h"

namespace TW_Mailer
{

    class ClientHandlers
    {
    public:
        static Message handleLogin();
        static Message handleSend();
        static Message handleList();
        static Message handleRead();
        static Message handleDel();
        static Message handleQuit();
    };

} // TW_Mailer

#endif //TW_MAILER_CLIENTHANDLERS_H
