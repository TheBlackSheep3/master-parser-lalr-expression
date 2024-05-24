#include <iostream>

#include "nodes.hpp"

int main() {
  AdditionExpression exp(new FactorTerm(new Literal(12)),
                         new TermExpression(new FactorTerm(new Literal(3))));
  std::cout << exp << "\n";
}
