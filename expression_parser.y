%skeleton "lalr1.cc"
%require	"3.8.2"
%header

%define api.token.constructor
%define api.value.type variant
%define parse.assert

%define api.namespace {nd}
%define api.parser.class {ExpressionParser}
%code requires {
	#include <string>
	namespace nd {
		class ExpressionDriver;
	}
}

%param { nd::ExpressionDriver& driver }

%locations

%define parse.trace
%define parse.error detailed
%define parse.lac full

%code {
#include "expression_driver.hpp"
}

%define api.token.prefix {TOK_}
%token <std::string>	ID
%token <int>					LIT
%token
	OP_PLUS		"+"
	OP_TIMES	"*"
	PAREN_OP	"("
	PAREN_CL	")"
;

%%
%start expression;
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

void nd::ExpressionParser::error(location_type const& loc, std::string const& err_message) {
	std::cerr << "Error: " << err_message << " at " << loc << "\n";
}
