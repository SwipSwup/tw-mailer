#include "Message.h"
#include <sstream>
#include <iostream>
#include <utility>
#include "ErrorCode.h"

namespace TW_Mailer
{
    //Parses the message string to a message object
    Message Message::parse(std::string string)
    {
        Message message;
        try
        {
            std::istringstream stream(string);
            std::string line;

            if (std::getline(stream, line))
            {
                message.command = static_cast<Command>(std::stoi(line));
            }

            while (std::getline(stream, line) && !line.empty())
            {
                size_t delimiterPos = line.find(':');
                if (delimiterPos != std::string::npos)
                {
                    std::string key = line.substr(0, delimiterPos);
                    std::string value = line.substr(delimiterPos + 1);

                    key.erase(0, key.find_first_not_of(" \t"));
                    key.erase(key.find_last_not_of(" \t") + 1);
                    value.erase(0, value.find_first_not_of(" \t"));
                    value.erase(value.find_last_not_of(" \t") + 1);

                    message.parameters[key] = value;
                }
            }

            std::string body;
            while (std::getline(stream, line))
            {
                body += line + "\n";
            }
            if (!body.empty() && body.back() == '\n')
            {
                body.pop_back();
            }
            message.body = body;
        }
        catch (const std::exception &e)
        {
            //Throw pasting error if something goes wrong
            throw PARSING_ERROR;
        }

        return message;
    }

    //Serailze the message into a string. Makes it easy to send information
    std::string Message::serialize()
    {
        std::ostringstream stream;

        stream << static_cast<int>(command) << "\n";

        for (std::pair<std::string, std::string> pair: parameters)
        {
            stream << pair.first << ":" << pair.second << "\n";
        }

        stream << "\n";

        stream << body;

        return stream.str();
    }
}
// TW_Mailer