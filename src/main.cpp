#include <iostream>
#include <complex>
#include <sstream>
#include <filesystem>

using namespace std;

int main() {
    // Flush after every std::cout / std:cerr
    cout << std::unitbuf; // console out.
    cerr << std::unitbuf; // console error.
    
    string commands[3] = { "exit", "echo", "type" };

    while (true) {
        cout << "$ ";
        string input;
        getline(cin, input);

        if (input.substr(0, 4) == commands[0]) { //Exit function
            return 0;
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
                cout << input.substr(5) << " not found\n";
            }
        }
        else { //Command not found function
            cout << input << ": command not found\n";
        }
    }
}
