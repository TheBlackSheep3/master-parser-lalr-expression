#pragma once

#ifndef yyFlexLexerOnce
#include <FlexLexer.h>
#endif

#include "parser.hh"

namespace nd {
class ExpressionScanner : public yyFlexLexer {
public:
  ExpressionScanner(std::istream *in) : yyFlexLexer(in) {};
  virtual ~ExpressionScanner() {};
  using FlexLexer::yylex;
  virtual int yylex(yy::parser::semantic_type *const lval,
                       yy::parser::location_type *location);
};
} // namespace nd
