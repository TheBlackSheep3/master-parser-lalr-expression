#pragma once

#include <memory>
#include <ostream>

namespace nd::Expression::Tree {
class Node {
public:
  virtual ~Node() = default;

  virtual std::string get_string() const = 0;
};

class Expression : public Node {
public:
  virtual ~Expression() = default;
};

class Term : public Node {
public:
  virtual ~Term() = default;
};

class Factor : public Node {
public:
  virtual ~Factor() = default;
};

class AdditionExpression : public Expression {
public:
  AdditionExpression(Term *term, Expression *expression)
      : m_term(term), m_expression(expression) {}
  virtual ~AdditionExpression() = default;

  std::string get_string() const override;

private:
  std::unique_ptr<Term> m_term;
  std::unique_ptr<Expression> m_expression;
};

class TermExpression : public Expression {
public:
  TermExpression(Term *term) : m_term(term) {}
  virtual ~TermExpression() = default;

  std::string get_string() const override;

private:
  std::unique_ptr<Term> m_term;
};

class MultiplicationTerm : public Term {
public:
  MultiplicationTerm(Factor *factor, Term *term)
      : m_factor(factor), m_term(term) {}
  virtual ~MultiplicationTerm() = default;

  std::string get_string() const override;

private:
  std::unique_ptr<Factor> m_factor;
  std::unique_ptr<Term> m_term;
};

class FactorTerm : public Term {
public:
  FactorTerm(Factor *factor) : m_factor(factor) {}
  virtual ~FactorTerm() = default;

  std::string get_string() const override;

private:
  std::unique_ptr<Factor> m_factor;
};

class Literal : public Factor {
public:
  Literal(int value) : m_value(value) {}
  virtual ~Literal() = default;

  std::string get_string() const override;

private:
  int m_value;
};

class Identifier : public Factor {
public:
  Identifier(std::string id) : m_id(id) {}
  virtual ~Identifier() = default;

  std::string get_string() const override;

private:
  std::string m_id;
};

class ParenthesisExpression : public Factor {
public:
  ParenthesisExpression(Expression *exp) : m_exp(exp) {}
  virtual ~ParenthesisExpression() = default;

  std::string get_string() const override;

private:
  std::unique_ptr<Expression> m_exp;
};
} // namespace nd::Expression::Tree

std::ostream &operator<<(std::ostream &ostream,
                         nd::Expression::Tree::Node const &printable);
