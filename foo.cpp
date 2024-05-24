#include <iostream>

#include "nodes.hpp"

using namespace nd::Expression::Tree;

int main() {
  AdditionExpression exp(new FactorTerm(new Literal(12)),
                         new TermExpression(new FactorTerm(new Literal(3))));
  std::cout << exp << "\n";
}
