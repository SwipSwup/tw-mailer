#include "src/Server/Server.h"
#include <iostream>

int main() {
    int port = 6543;
    TW_Mailer::Server server(port, "./SpoolDir");

    if (!server.start()) {
        return EXIT_FAILURE;
    }

    server.run();

    return EXIT_SUCCESS;
}