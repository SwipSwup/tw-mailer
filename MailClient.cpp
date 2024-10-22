#include "src/Client/Client.h"

int main(int argc, char* argv[])
{
    std::string ip = (argc > 1) ? argv[1] : "127.0.0.1";
    int port = 6543;

    TW_Mailer::Client client(ip, port);

    if (!client.connectToServer())
    {
        return EXIT_FAILURE;
    }

    client.run();

    return EXIT_SUCCESS;
}