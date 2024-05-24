%option c++
%option noyywrap
%option yyclass="nd::Expression::Lexer"
%option nodefault

%{
#include <cstdlib>
#include <string>

#include "expression_lexer.hpp"
#undef YY_DECL
#define YY_DECL int nd::Expression::Lexer::yylex(nd::Expression::Parser::semantic_type * const lval, nd::Expression::Parser::location_type * loc)

#include "expression_parser.hpp"
%}

%%
[ \t]	; // ignore whitespace

[a-zA-Z_][a-zA-Z0-9_]*	{ yylval->build<std::string>(yytext);return(nd::Expression::Parser::token::ID); }
[1-9][0-9]*							{ yylval->build<int>(atoi(yytext));return(nd::Expression::Parser::token::LIT); }
"+"											{ return(nd::Expression::Parser::token::OP_PLUS); }
"*"											{ return(nd::Expression::Parser::token::OP_TIMES); }
"("											{ return(nd::Expression::Parser::token::PAREN_OP); }
")"											{ return(nd::Expression::Parser::token::PAREN_CL); }
%%
