#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

#include "config.hpp"
#include "mc_driver.hpp"

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

void foo(MC::MC_Driver& driver, std::istream& stream) {
  driver.parse(stream);
  driver.print(std::cout);
}

int main(int argc, char const *argv[]) {
  MC::MC_Driver driver;
  if (1 == argc) {
    foo(driver, std::cin);
    return EXIT_SUCCESS;
  }
  if (2 == argc) {
    if (0 == std::strncmp(argv[1], "-h", 2)) {
      print_help();
      return EXIT_SUCCESS;
    } else if (0 == std::strncmp(argv[1], "-i", 2)) {
      std::string line;
      while (true) {
        std::stringstream strstream;
        std::getline(std::cin, line);
        strstream << line;
        foo(driver, strstream);
      }
    } else if (0 == std::strncmp(argv[1], "-V", 2)) {
      std::cout << PROJECT_EXECUTABLE << " version " << PROJECT_VERSION << std::endl;
      return EXIT_SUCCESS;
    } else {
      print_help();
      return EXIT_FAILURE;
    }
  } else if (3 == argc && 0 == std::strncmp(argv[1], "-f", 2)) {
    std::ifstream in_file(argv[2]);
    if (!in_file.good()) {
      return EXIT_FAILURE;
    }
    else {
      foo(driver, in_file);
      return EXIT_SUCCESS;
    }
  } else {
    print_help();
    return EXIT_FAILURE;
  }
}
