#ifndef TW_MAILER_ERRORCODE_H
#define TW_MAILER_ERRORCODE_H

namespace TW_Mailer
{
    //Custom error codes
    enum ErrorCode
    {
        NONE,
        USER_NOT_FOUND,
        INVALID_MAIL_INDEX,
        PARSING_ERROR,
        LDAP_CONNECTION_ERROR,
        LDAP_NO_SECURE_CONNECTION,
        LDAP_CANT_LOAD_OPT,
        LDAP_INVALID_USERNAME_OR_PASSWORD,
        LDAP_TO_MANY_REQUESTS

    };

} // TW_Mailer

#endif //TW_MAILER_ERRORCODE_H
