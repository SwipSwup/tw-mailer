#include <iostream>
#include "src/Client/Client.h"

int main(int argc, char* argv[])
{
    if(argc < 2) {
        perror("Invalid argument count");
        return EXIT_FAILURE;
    }

    TW_Mailer::Client client(argv[1], std::stoi(argv[2]));

    if (!client.connectToServer())
    {
        perror("Unable to connect to mail server");
        return EXIT_FAILURE;
    }

    client.run();

    return EXIT_SUCCESS;
}