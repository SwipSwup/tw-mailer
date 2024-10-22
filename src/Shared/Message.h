#ifndef TW_MAILER_MESSAGE_H
#define TW_MAILER_MESSAGE_H

#include <string>
#include <map>
#include "Command.h"

namespace TW_Mailer
{

    struct Message
    {
    public:
        Command command;
        std::string body;

        std::map<std::string, std::string> parameters;

        std::string serialize();

        static Message parse(std::string string);
    };

} // TW_Mailer

#endif //TW_MAILER_MESSAGE_H
