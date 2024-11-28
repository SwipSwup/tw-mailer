#include "MailManager.h"
#include "Mail.h"
#include "../../Shared/ErrorCode.h"
#include <utility>

namespace TW_Mailer
{
    MailManager::MailManager(std::string mailDirectory) : mailDir(std::move(mailDirectory))
    {
        // Create the mail folder if it doesnt exist
        if (!std::filesystem::exists(mailDir))
        {
            std::filesystem::create_directories(mailDir);
        }
    }

    void MailManager::saveMail(const Mail &mail)
    {
        std::string senderDir = mailDir + "/" + mail.sender + SENT_DIRECTORY;
        std::string receiverDir = mailDir + "/" + mail.receiver + RECEIVED_DIRECTORY;

        //check if the coresponding folders exist
        if (!std::filesystem::exists(senderDir))
        {
            std::filesystem::create_directories(senderDir);
        }

        if (!std::filesystem::exists(receiverDir))
        {
            std::filesystem::create_directories(receiverDir);
        }

        //create the Mail files
        createMailFile(mail, senderDir);
        createMailFile(mail, receiverDir);
    }

    //Helper function to create the mail file
    void MailManager::createMailFile(const Mail &mail, const std::string &dir) const
    {
        std::string filePath =
                dir + "/" +
                std::to_string(std::hash<std::string>{}(mail.sender + mail.receiver + mail.subject + mail.body)) +
                ".txt";
        std::ofstream file(filePath);
        file << "Sender: " << mail.sender << std::endl;
        file << "Receiver: " << mail.receiver << std::endl << std::endl;
        file << "Subject: " << mail.subject << std::endl;
        file << mail.body;
        file.close();
    }

    //Looks through all the folders and return the subjects as one string
    std::string MailManager::getAllMails(const std::string &username)
    {
        std::stringstream stream;
        std::string sentDir = mailDir + "/" + username + SENT_DIRECTORY;
        std::string receivedDir = mailDir + "/" + username + RECEIVED_DIRECTORY;

        int index = 1;

        //Throw custom error code if the user doesnt exist
        if(!std::filesystem::exists(mailDir + "/" + username)) {
            throw USER_NOT_FOUND;
        }

        if (std::filesystem::exists(receivedDir))
        {
            stream << "Received Emails:" << std::endl;
            stream << getAllSubjects(receivedDir, &index);
        }

        if (std::filesystem::exists(sentDir))
        {
            stream << std::endl << "===============================================================" << std::endl;
            stream << "Sent Emails:" << std::endl;
            stream << getAllSubjects(sentDir, &index);
        }

        return stream.str();
    }

    //Another helper function
    std::string MailManager::getAllSubjects(const std::string &sentDir, int* index) const
    {
        std::stringstream stream;

        for (const std::filesystem::directory_entry &entry: std::filesystem::directory_iterator(sentDir))
        {
            std::ifstream file(entry.path());
            std::string line;
            for (int i = 0; i < 4; ++i, std::getline(file, line));

            const std::string prefix = "Subject: ";
            if (line.rfind(prefix, 0) == 0) {
                line = line.substr(prefix.length());
            }

            stream << (*index)++ << ": " << line << std::endl;
            file.close();
        }
        return stream.str();
    }

    //Gets all the files as on vector
    std::vector<std::string> MailManager::getAllFiles(const std::string& username) {
        std::string receivedFolder = mailDir + "/" + username + RECEIVED_DIRECTORY;
        std::string sentFolder = mailDir + "/" + username + SENT_DIRECTORY;

        std::vector<std::string> allFiles;

        if (std::filesystem::exists(receivedFolder)) {
            for (const std::filesystem::directory_entry &entry : std::filesystem::directory_iterator(receivedFolder)) {
                allFiles.push_back(entry.path().string());
            }
        }

        if (std::filesystem::exists(sentFolder)) {
            for (const std::filesystem::directory_entry &entry : std::filesystem::directory_iterator(sentFolder)) {
                allFiles.push_back(entry.path().string());
            }
        }

        return allFiles;
    }

    std::string MailManager::getMail(const std::string &username, int id)
    {
        //Throw error if the user deosnt exist
        if(!std::filesystem::exists(mailDir + "/" + username)) {
            throw USER_NOT_FOUND;
        }

        std::vector<std::string> mails = getAllFiles(username);

        //Throw error if the index is out of bounds
        if (id < 1 || id > mails.size())
        {
            throw INVALID_MAIL_INDEX;
        }

        std::ifstream file;
        file.open(mails[id - 1]);

        std::stringstream content;
        content << file.rdbuf();

        file.close();
        return content.str();
    }

    void MailManager::deleteMail(std::string username, int id)
    {
        //Basically the same as get mail
        if(!std::filesystem::exists(mailDir + "/" + username)) {
            throw USER_NOT_FOUND;
        }

        std::vector<std::string> mails = getAllFiles(username);

        if (id < 1 || id > mails.size())
        {
            throw INVALID_MAIL_INDEX;
        }

        std::filesystem::remove(mails[id - 1]);
    }


} // TW_Mailer