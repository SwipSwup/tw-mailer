cmake_minimum_required(VERSION 3.22)
project(tw_mailer)

set(CMAKE_CXX_STANDARD 20)

add_executable(tw_server
        MailServer.cpp
        src/Server/Server.cpp
        src/Server/Server.h
        src/Shared/Message.cpp
        src/Shared/Message.h
        src/Shared/Command.h
        src/Server/ServerHandler.cpp
        src/Server/ServerHandler.h
        src/Shared/NetUtilities.cpp
        src/Shared/NetUtilities.h
        src/Server/MailManager/MailManager.cpp
        src/Server/MailManager/MailManager.h
        src/Server/MailManager/Mail.h
        src/Shared/ErrorCode.h
)

add_executable(tw_client
        MailClient.cpp
        src/Client/Client.cpp
        src/Client/Client.h
        src/Shared/Message.cpp
        src/Shared/Message.h
        src/Shared/Command.h
        src/Shared/NetUtilities.cpp
        src/Shared/NetUtilities.h
        src/Client/ClientHandlers.cpp
        src/Client/ClientHandlers.h)

add_executable(tw_client2
        MailClient.cpp
        src/Client/Client.cpp
        src/Client/Client.h
        src/Shared/Message.cpp
        src/Shared/Message.h
        src/Shared/Command.h
        src/Shared/NetUtilities.cpp
        src/Shared/NetUtilities.h
        src/Client/ClientHandlers.cpp
        src/Client/ClientHandlers.h)

