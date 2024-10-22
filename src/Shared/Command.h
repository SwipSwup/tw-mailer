#ifndef TW_MAILER_COMMAND_H
#define TW_MAILER_COMMAND_H

namespace TW_Mailer
{
    enum Command
    {
        OK,
        ERR,
        SEND,
        LIST,
        READ,
        DEL,
        QUIT
    };

} // TW_Mailer

#endif //TW_MAILER_COMMAND_H
