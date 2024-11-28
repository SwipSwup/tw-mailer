//
// Created by david on 28/11/2024.
//

#ifndef TW_MAILER_LDAPHANDLER_H
#define TW_MAILER_LDAPHANDLER_H

#include <string>
#include <ldap.h>
#include "../Shared/ErrorCode.h"

namespace TW_Mailer
{

    class LdapHandler
    {
    private:
        const std::string ldapUri = "ldap://ldap.technikum-wien.at:389";
        const std::string baseDn = "ou=people,dc=technikum-wien,dc=at";

        LDAP* handle;

    public:
        LdapHandler();

        bool validateUser(const std::string& username, const std::string& password);
    };

} // TW_Mailer

#endif //TW_MAILER_LDAPHANDLER_H
