#include <iostream>
#include <string>

#include "nodes.hpp"

using namespace nd::Expression::Tree;
using namespace std::literals::string_literals;

int main() {
  AdditionExpression exp(new FactorTerm(new Literal(12)),
                         new TermExpression(new FactorTerm(new Literal(3))));
  std::cout << exp << "\n";
  AdditionExpression other(
      new FactorTerm(new Literal(100)),
      new AdditionExpression(
          new MultiplicationTerm(
              new Identifier("x"s),
              new FactorTerm(new ParenthesisExpression(new AdditionExpression(
                  new FactorTerm(new Literal(32)),
                  new TermExpression(new FactorTerm(new Identifier("y"s))))))),
          new TermExpression(new FactorTerm(new Literal(19)))));
  std::cout << other << "\n";
}
