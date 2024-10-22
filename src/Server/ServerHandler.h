#ifndef TW_MAILER_SERVERHANDLER_H
#define TW_MAILER_SERVERHANDLER_H

#include "../Shared/Message.h"

namespace TW_Mailer
{

    class ServerHandler
    {
    public:
        static Message handleSend(Message message);
        static Message handleList(Message message);
        static Message handleRead(Message message);
        static Message handleDel(Message message);
        static Message handleQuit(Message message);
    };

} // TW_Mailer

#endif //TW_MAILER_SERVERHANDLER_H
