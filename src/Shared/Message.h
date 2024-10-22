//
// Created by david on 22/10/2024.
//

#ifndef TW_MAILER_MESSAGE_H
#define TW_MAILER_MESSAGE_H

#include <string>
#include <map>
#include "MessageCmd.h"

namespace TW_Mailer
{

    struct Message
    {
    public:
        MessageCmd command;
        std::string message;

        std::map<std::string, std::string> headers;

        static Message* Parse(std::string string);

        std::string serialize();
    };

} // TW_Mailer

#endif //TW_MAILER_MESSAGE_H
