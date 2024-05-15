#include "expression_driver.hpp"
#include "expression_parser.hpp"

int nd::ExpressionDriver::parse (std::istream& input) {
  location.initialize(&input);
  scan_begin();
  nd::ExpressionParser parser(*this);
  parser.set_debug_level(trace_parsing);
  int res = parser();
  scan_end();
  return res;
}
