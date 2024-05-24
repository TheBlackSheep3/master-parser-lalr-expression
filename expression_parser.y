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

%token <std::string>	ID
%token <int>					LIT
%token								OP_PLUS
%token								OP_TIMES
%token								PAREN_OP
%token								PAREN_CL

%locations

%%
expression
	: term OP_PLUS expression
	| term
	;

term
	: factor OP_TIMES term
	| factor
	;

factor
	: LIT
	| ID
	| PAREN_OP expression PAREN_CL
	;
%%

void nd::Expression::Parser::error(location_type const& loc, std::string const& err_message) {
	std::cerr << "Error: " << err_message << " at " << loc << "\n";
}
