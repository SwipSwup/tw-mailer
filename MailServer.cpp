#include "src/Server/Server.h"
#include <iostream>

int main(int argc, char* argv[]) {
    if(argc < 2) {
        std::cout << "Invalid argument count";
        return EXIT_FAILURE;
    }

    TW_Mailer::Server server(std::stoi(argv[1]), argv[2]);

    if (!server.start()) {
        return EXIT_FAILURE;
    }

    server.run();

    return EXIT_SUCCESS;
}