//
// Created by david on 22/10/2024.
//

#ifndef TW_MAILER_MAILMANAGER_H
#define TW_MAILER_MAILMANAGER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <filesystem>
#include "Mail.h"

#define SENT_DIRECTORY "/sent"
#define RECEIVED_DIRECTORY "/received"

namespace TW_Mailer
{

    class MailManager
    {
    public:
        MailManager(std::string mailDirectory);

        void saveMail(const Mail& mail);

        std::string getAllMails(const std::string& username);

        std::string getMail(const std::string& username, int id);

        void deleteMail(std::string username, int id);

    private:
        std::string mailDir;

        void createMailFile(const Mail& mail, const std::string &dir) const;

        std::vector<std::string> getAllFiles(const std::string& username);

        std::string getAllSubjects(const std::string &sentDir, int* index) const;
    };

} // TW_Mailer

#endif //TW_MAILER_MAILMANAGER_H
