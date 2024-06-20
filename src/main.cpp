#include <iostream>
#include <complex>

int main() {
    // Flush after every std::cout / std:cerr
    std::cout << std::unitbuf;
    std::cerr << std::unitbuf;
    std::string commands[3] = { "exit", "echo", "type" };

    while (true) {
        std::cout << "$ ";
        std::string input;
        std::getline(std::cin, input);

        if (input.substr(0, 4) == commands[0]) { //Exit function
            return 0;
        }
        else if (input.substr(0, 4) == commands[1]) { //Echo function
            std::cout << input.substr(5) << "\n";
        }
        else if (input.substr(0, 4) == commands[2]) { //Type function

        }
        else { //Command not found function
            std::cout << input << ": command not found\n";
        }
    }
}
