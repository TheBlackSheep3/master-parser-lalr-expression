#pragma once

#include <istream>
#ifndef yyFlexLexerOnce
#include <FlexLexer.h>
#endif

#include "expression_parser.hpp"
#include "location.hh"

namespace nd::Expression {
class Lexer : public yyFlexLexer {
 public:
  Lexer(std::istream* in) : yyFlexLexer(in) {}
  Lexer(Lexer const& other) = delete;
  Lexer(Lexer&& other) = delete;
  Lexer& operator=(Lexer const& other) = delete;
  Lexer& operator=(Lexer&& other) = delete;
  virtual ~Lexer() = default;

  using FlexLexer::yylex;
  virtual int yylex(nd::Expression::Parser::semantic_type* const lval,
                    nd::Expression::Parser::location_type* location);

 private:
  nd::Expression::Parser::semantic_type* yylval = nullptr;
};
}  // namespace nd::Expression
