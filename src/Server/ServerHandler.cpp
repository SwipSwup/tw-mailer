#include "ServerHandler.h"
#include "Server.h"
#include "MailManager/MailManager.h"

namespace TW_Mailer
{
    Message ServerHandler::handleSend(Message message)
    {
        if (message.parameters["subject"].length() > 80)
            return Message{ERR, "Subject length too long"};

        Server::mailManager->saveMail(Mail{
                message.parameters["sender"],
                message.parameters["receiver"],
                message.parameters["subject"],
                message.body
        });

        return Message{OK};
    }

    Message ServerHandler::handleList(Message message)
    {
        return Message{OK, Server::mailManager->getAllMails(message.parameters["username"])};
    }

    Message ServerHandler::handleRead(Message message)
    {
        std::string mail;
        mail = Server::mailManager->getMail(
                message.parameters["username"],
                std::stoi(message.parameters["messageNumber"])
        );

        return mail.empty() ? Message{ERR} : Message{OK, mail};
    }

    Message ServerHandler::handleDel(Message message)
    {
        Server::mailManager->deleteMail(
                message.parameters["username"],
                std::stoi(message.parameters["messageNumber"])
        );

        return Message{OK};
    }

    Message ServerHandler::handleQuit(Message message)
    {
        return Message{QUIT};
    }
}
// TW_Mailer