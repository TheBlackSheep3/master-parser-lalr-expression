%skeleton "lalr1.cc"
%require	"3.0"
%defines
%define api.namespace {nd::Expression}
%define api.parser.class {Parser}
%code requires {
	namespace nd::Expression {
		class Driver;
		class Lexer;
	}
	#include "nodes.hpp"
}

%parse-param { Lexer & lexer }
%parse-param { Driver & driver }

%define api.value.type variant
%define parse.assert

%code{
	#include <iostream>
	#include <cstdlib>
	#include <fstream>

	#include "expression_driver.hpp"

#undef yylex
#define yylex lexer.yylex
}

%token <nd::Expression::Tree::Identifier*>	ID
%token <nd::Expression::Tree::Literal*>			LIT
%token																			OP_PLUS
%token																			OP_TIMES
%token																			PAREN_OP
%token																			PAREN_CL
%nterm <nd::Expression::Tree::Expression*>	expression
%nterm <nd::Expression::Tree::Term*>				term
%nterm <nd::Expression::Tree::Factor*>			factor

%locations

%%
expression
	: term OP_PLUS expression	{ $$ = new Tree::AdditionExpression($1, $3); }
	| term										{ $$ = new Tree::TermExpression($1); }
	;

term
	: factor OP_TIMES term	{ $$ = new Tree::MultiplicationTerm($1, $3); }
	| factor								{ $$ = new Tree::FactorTerm($1); }
	;

factor
	: LIT														{}
	| ID														{}
	| PAREN_OP expression PAREN_CL	{ $$ = new Tree::ParenthesisExpression($2); }
	;
%%

void nd::Expression::Parser::error(location_type const& loc, std::string const& err_message) {
	std::cerr << "Error: " << err_message << " at " << loc << "\n";
}
