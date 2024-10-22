//
// Created by david on 22/10/2024.
//

#ifndef TW_MAILER_MESSAGECMD_H
#define TW_MAILER_MESSAGECMD_H

namespace TW_Mailer
{
    enum MessageCmd
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

#endif //TW_MAILER_MESSAGECMD_H
