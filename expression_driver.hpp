#pragma once
#include <istream>
#include <memory>

#include "expression_lexer.hpp"
#include "expression_parser.hpp"

namespace nd {
class ExpressionDriver {
public:
  ExpressionDriver() = default;
  ExpressionDriver(ExpressionDriver const& other) = delete;
  ExpressionDriver(ExpressionDriver&& other) {
    parser.swap(other.parser);
    lexer.swap(other.lexer);
  }
  ExpressionDriver& operator=(ExpressionDriver const& other) = delete;
  ExpressionDriver& operator=(ExpressionDriver&& other) {
    parser.swap(other.parser);
    lexer.swap(other.lexer);
    return *this;
  }
  virtual ~ExpressionDriver();

  void parse(std::istream& input_stream);
private:
  std::unique_ptr<nd::ExpressionParser> parser;
  std::unique_ptr<nd::ExpressionLexer> lexer;
};
}
