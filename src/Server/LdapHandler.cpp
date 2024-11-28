//
// Created by david on 28/11/2024.
//

#include "LdapHandler.h"
#include <ldap.h>

namespace TW_Mailer
{
    bool LdapHandler::validateUser(const std::string &username, const std::string &password)
    {
        std::string userDn = "uid=" + username + "," + baseDn;

        BerValue credentials;
        credentials.bv_val = const_cast<char*>(password.c_str());
        credentials.bv_len = password.size();

        int response = ldap_sasl_bind_s(
                handle,
                userDn.c_str(),
                LDAP_SASL_SIMPLE,
                &credentials,
                nullptr,
                nullptr,
                nullptr
        );

        return response == LDAP_SUCCESS;
    }

    LdapHandler::LdapHandler()
    {

        if (ldap_initialize(&handle, ldapUri.c_str()) != LDAP_SUCCESS)
        {
            throw LDAP_CONNECTION_ERROR;
        }
        int version = LDAP_VERSION3;
        if (ldap_set_option(handle, LDAP_OPT_PROTOCOL_VERSION, &version) != LDAP_OPT_SUCCESS)
        {
            throw LDAP_CANT_LOAD_OPT;
        }

        if (ldap_start_tls_s(handle, nullptr, nullptr) != LDAP_SUCCESS)
        {
            throw LDAP_NO_SECURE_CONNECTION;
        }
    }
} // TW_Mailer