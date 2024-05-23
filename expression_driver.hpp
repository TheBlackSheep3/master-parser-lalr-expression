#pragma once
#include "expression_parser.tab.hpp"
#include <istream>
#include <string>

#define YY_DECL                                                                \
  nd::ExpressionParser::symbol_type yylex(nd::ExpressionDriver &driver)
YY_DECL;

namespace nd {
class ExpressionDriver {
public:
  ExpressionDriver();
  int parse(std::istream &input);
  bool trace_parsing;
  std::string tree;

  void scan_begin();
  void scan_end();
  bool trace_scanning;
  nd::location location;
};
} // namespace nd
