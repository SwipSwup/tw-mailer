#ifndef TW_MAILER_COMMAND_H
#define TW_MAILER_COMMAND_H

namespace TW_Mailer
{
    //All available commands
    enum Command
    {
        OK,
        ERR,
        LOGIN,
        SEND,
        LIST,
        READ,
        DEL,
        QUIT
    };

} // TW_Mailer

#endif //TW_MAILER_COMMAND_H
