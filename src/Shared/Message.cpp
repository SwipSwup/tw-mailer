//
// Created by david on 22/10/2024.
//

#include "Message.h"
#include <sstream>

namespace TW_Mailer
{
    Message* Message::Parse(std::string string)
    {
        Message* message = new Message();
        std::istringstream stream(string);
        std::string line;

        if (std::getline(stream, line))
        {
            message->command = static_cast<MessageCmd>(std::stoi(line));
        }

        while (std::getline(stream, line) && !line.empty())
        {
            size_t delimiterPos = line.find(':');
            if (delimiterPos != std::string::npos)
            {
                std::string headerKey = line.substr(0, delimiterPos);
                std::string headerValue = line.substr(delimiterPos + 1);
                message->headers[headerKey] = headerValue;
            }
        }

        std::string body;
        while (std::getline(stream, line))
        {
            body += line + "\n";
        }
        message->message = body;

        return message;
    }

    std::string Message::serialize()
    {
        std::ostringstream stream;

        stream << static_cast<int>(command) << "\n";

        for (std::pair<std::string, std::string> header: headers)
        {
            stream << header.first << ":" << header.second << "\n";
        }

        stream << "\n";

        stream << message;

        return stream.str();
    }
// TW_Mailer