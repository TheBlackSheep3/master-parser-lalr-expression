#pragma once
#include <istream>
#include <memory>

#include "expression_lexer.hpp"
#include "expression_parser.hpp"

namespace nd::Expression {
class Driver {
 public:
  Driver() = default;
  Driver(Driver const& other) = delete;
  Driver(Driver&& other) {
    parser.swap(other.parser);
    lexer.swap(other.lexer);
  }
  Driver& operator=(Driver const& other) = delete;
  Driver& operator=(Driver&& other) {
    parser.swap(other.parser);
    lexer.swap(other.lexer);
    return *this;
  }
  virtual ~Driver() = default;

  void parse(std::istream& input_stream);

 private:
  std::unique_ptr<nd::Expression::Parser> parser;
  std::unique_ptr<nd::Expression::Lexer> lexer;
};
}  // namespace nd::Expression
