#include "expression_driver.hpp"
#include "expression_lexer.hpp"
#include <cstdlib>
#include <iostream>
#include <memory>
#include <new>

void nd::ExpressionDriver::parse(std::istream &stream) {
  if (!stream.good() || stream.eof()) {
    return;
  }
  try {
    lexer = std::make_unique<nd::ExpressionLexer>(&stream);
  } catch (std::bad_alloc &ba) {
    std::cerr << "Failed to allocate lexer: (" << ba.what() << "), exiting!\n";
    std::exit(EXIT_FAILURE);
  }

  try {
    parser = std::make_unique<nd::ExpressionParser>(*lexer, *this);
  } catch (std::bad_alloc &ba) {
    std::cerr << "Failed to allocate parser: (" << ba.what() << "), exiting!\n";
    std::exit(EXIT_FAILURE);
  }

  int const accept(0);
  if (accept != parser->parse()) {
    std::cerr << "Parse failed!\n";
  }
  return;
}
