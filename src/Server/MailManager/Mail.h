#ifndef TW_MAILER_MAIL_H
#define TW_MAILER_MAIL_H

#include <string>

namespace TW_Mailer
{
    //Container to store data for mails
    struct Mail
    {
    public:
        const std::string sender;
        const std::string receiver;
        const std::string subject;
        const std::string body;
    };

} // TW_Mailer

#endif //TW_MAILER_MAIL_H
