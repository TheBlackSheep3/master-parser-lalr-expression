#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>

#include "config.hpp"

void print_help() {
  std::cout << "Usage: " << PROJECT_EXECUTABLE << " [options]\n";
  std::cout << "  -h       Print this message and exit.\n";
  std::cout << "  -f FILE  Read the expression from FILE.\n";
  std::cout << "  -i       Run the parser interactively.\n";
  std::cout << "  -V       Print the version of " << PROJECT_EXECUTABLE
            << " and exit.\n\n";
  std::cout << "If no other option is provided, the expression is read from "
               "the standard input stream."
            << std::endl;
}

int main(int argc, char const *argv[]) {
  if (1 == argc) {
    std::string input;
    std::cin >> input;
    std::cout << "Read from standard input:\n";
    std::cout << input << std::endl;
    return EXIT_SUCCESS;
  }
  if (2 == argc) {
    if (0 == std::strncmp(argv[1], "-h", 2)) {
      print_help();
      return EXIT_SUCCESS;
    } else if (0 == std::strncmp(argv[1], "-i", 2)) {
      std::string line;
      while (true) {
        std::getline(std::cin, line);
        std::cout << line << std::endl;
      }
    } else if (0 == std::strncmp(argv[1], "-V", 2)) {
      std::cout << PROJECT_EXECUTABLE << " version " << PROJECT_VERSION << std::endl;
      return EXIT_SUCCESS;
    } else {
      print_help();
      return EXIT_FAILURE;
    }
  } else if (3 == argc && 0 == std::strncmp(argv[1], "-f", 2)) {
    std::cout << "Reading file: " << argv[2] << std::endl;
    return EXIT_SUCCESS;
  } else {
    print_help();
    return EXIT_FAILURE;
  }
}
