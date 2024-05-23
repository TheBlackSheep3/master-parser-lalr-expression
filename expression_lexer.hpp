#pragma once

#include <istream>
#ifndef yyFlexLexerOnce
#include <FlexLexer.h>
#endif

#include "expression_parser.hpp"
#include "location.hh"

namespace nd {
class ExpressionLexer : public yyFlexLexer {
public:
  ExpressionLexer(std::istream *in) : yyFlexLexer(in) {}
  ExpressionLexer(ExpressionLexer const &other) = delete;
  ExpressionLexer(ExpressionLexer &&other) = delete;
  ExpressionLexer &operator=(ExpressionLexer const &other) = delete;
  ExpressionLexer &operator=(ExpressionLexer &&other) = delete;
  virtual ~ExpressionLexer() = default;

  using FlexLexer::yylex;
  virtual int yylex(nd::ExpressionParser::semantic_type *const lval,
                    nd::ExpressionParser::location_type *location);

private:
  nd::ExpressionParser::semantic_type *yylval = nullptr;
};
} // namespace nd
