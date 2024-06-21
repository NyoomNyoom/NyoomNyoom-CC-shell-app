#include <iostream>
#include <complex>
#include <sstream>
#include <filesystem>

using namespace std;

string get_path(string command) {
    string path_env = std::getenv("PATH");

    stringstream ss(path_env);
    string path;

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

        //Grabs the command from the first word of the script.
        stringstream ss(input);
        string command;
        ss >> command;


        if (command == commands[0]) { //Exit function
            running = false;
        }
        else if (command == commands[1]) { //Echo function
            cout << input.substr(5) << "\n";
        }
        else if (command == commands[2]) { //Type function
            bool found = false; //variable to hold a boolean for when a function is found.
            string typeParam = input.substr(5);

            for (int i = 0; i < 4; i++) { // Loops over the array to find if the command exists in the array.
                if (commands[i] == typeParam) {
                    found = true;
                    break; //Stops the for loop from continuing.
                }
            }

            if (found) {
                cout << typeParam << " is a shell builtin\n";
            }
            else {
                string path = get_path(typeParam);

                if (path.empty()) {
                    cout << typeParam << ": not found\n";
                }
                else {
                    cout << typeParam << " is " << path << endl;
                }
            }
        }
        else if (!get_path(command).empty()) {
            string commandWithPath = get_path(command); 
            string paramter = input.substr(input.find(" ") + 1);
            string output = commandWithPath + " " + paramter;

            system(&output[0]);

        } else { //Command not found function
            cout << input << ": command not found\n";
        }
    }

    return 0;
}
