#include "nodes.hpp"
#include <string>

std::ostream &operator<<(std::ostream &ostream, Node const &printable) {
  ostream << printable.get_string();
  return ostream;
}
std::string AdditionExpression::get_string() const {
  return std::string("add(" + m_term->get_string() + "," +
                     m_expression->get_string() + ")");
}

std::string TermExpression::get_string() const { return m_term->get_string(); }

std::string MultiplicationTerm::get_string() const {
  return std::string("mul(" + m_factor->get_string() + "," +
                     m_term->get_string() + ")");
}

std::string FactorTerm::get_string() const { return m_factor->get_string(); }

std::string Literal::get_string() const {
  return std::string("Lit=" + std::to_string(m_value));
}

std::string Identifier::get_string() const { return std::string("Id=" + m_id); }

std::string ParenthesisExpression::get_string() const {
  return std::string("Parenthesis(" + m_exp->get_string() + ")");
}
