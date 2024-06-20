#include <iostream>
#include <complex>
#include <sstream>
#include <filesystem>

using namespace std;

std::string get_path(std::string command) {
    std::string path_env = std::getenv("PATH");

    std::stringstream ss(path_env);
    std::string path;

    while (!ss.eof()) {
        getline(ss, path, ':');

        string abs_path = path + '/' + command;

        if (filesystem::exists(abs_path)) {
            return abs_path;
        }
    }
    return "";
}

int main() {
    string commands[3] = { "exit", "echo", "type" };
    bool running = true;

    while (running) {
        // Flush after every std::cout / std:cerr
        cout << std::unitbuf; // console out.
        cerr << std::unitbuf; // console error.
        cout << "$ ";

        string input;
        getline(cin, input);

        if (input.substr(0, 4) == commands[0]) { //Exit function
            running = false;
        }
        else if (input.substr(0, 4) == commands[1]) { //Echo function
            cout << input.substr(5) << "\n";
        }
        else if (input.substr(0, 4) == commands[2]) { //Type function
            bool found = false; //variable to hold a boolean for when a function is found.

            for (int i = 0; i < 4; i++) { // Loops over the array to find if the command exists in the array.
                if (commands[i] == input.substr(5)) {
                    found = true;
                    break; //Stops the for loop from continuing.
                }
            }

            if (found) {
                cout << input.substr(5) << " is a shell builtin\n";
            } else {
                string path = get_path(input.substr(5));

                if (path.empty()) {
                    cout << input << ": not found\n";
                }
                else {
                    cout << input.substr(5) << " is " << path << endl;
                }
            }
        } else { //Command not found function
            cout << input << ": command not found\n";
        }
    }

    return 0;
}
