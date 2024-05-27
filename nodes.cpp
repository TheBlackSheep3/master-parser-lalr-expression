#include "nodes.hpp"
#include <string>

std::ostream &operator<<(std::ostream &ostream,
                         nd::Expression::Tree::Node const &printable) {
  ostream << printable.get_string();
  return ostream;
}
std::string nd::Expression::Tree::AdditionExpression::get_string() const {
  return std::string("E(" + m_term->get_string() + "," +
                     m_expression->get_string() + ")");
}

std::string nd::Expression::Tree::TermExpression::get_string() const {
  return std::string("E(" + m_term->get_string() + ")");
}

std::string nd::Expression::Tree::MultiplicationTerm::get_string() const {
  return std::string("T(" + m_factor->get_string() + "," +
                     m_term->get_string() + ")");
}

std::string nd::Expression::Tree::FactorTerm::get_string() const {
  return std::string("T(" + m_factor->get_string() + ")");
}

std::string nd::Expression::Tree::Literal::get_string() const {
  return std::to_string(m_value);
}

std::string nd::Expression::Tree::Identifier::get_string() const {
  return m_id;
}

std::string nd::Expression::Tree::ParenthesisExpression::get_string() const {
  return m_exp->get_string();
}
