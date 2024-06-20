#include <iostream>
#include <complex>

int main() {
  // Flush after every std::cout / std:cerr
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;  

  while (true){
    std::cout << "$ ";
    std::string input;
    std::getline(std::cin, input);

    if (input.substr(0,4) == "exit") { //Exit function
        return 0;
    } else if (input.substr(0,4) == "echo") { //Echo function
        std::cout << input.substr(4)<<"\n";
    } else { //Command not found function
        std::cout << input <<": command not found\n";
    }
  }
}
