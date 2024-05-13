#pragma once

#ifndef yyFlexLexerOnce
#include <FlexLexer.h>
#endif

#include "expression_parser.tab.hpp"

namespace nd {
class ExpressionScanner : public yyFlexLexer {
public:
  ExpressionScanner(std::istream *in) : yyFlexLexer(in) {};
  virtual ~ExpressionScanner() {};
  int FlexLexer::yylex(nd::ExpressionScanner::semantic_type *const lval,
                       nd::ExpressionScanner::location_type *location);

private:
  nd::ExpressionScanner::semantic_type *yylval = nullptr;
};
} // namespace nd
