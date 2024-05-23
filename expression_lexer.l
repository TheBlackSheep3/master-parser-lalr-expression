%option c++
%option noyywrap
%option yyclass="nd::ExpressionScanner"
%option nodefault

%{
#include <cerrno>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>

#include "expression_scanner.hpp"
#undef YY_DECL

#include "expression_parser.tab.hpp"
#include "expression_driver.hpp"
%}

%%
[ \t]	; // ignore whitespace

[a-zA-Z_][a-zA-Z0-9_]*	{ yylval->build<std::string>(yytext);return(nd::ExpressionParser::token::ID); }
[1-9][0-9]*							{ yylval->build<int>(atoi(yytext));return(nd::ExpressionParser::token::LIT); }
"+"											{ return(nd::ExpressionParser::token::OP_PLUS); }
"*"											{ return(nd::ExpressionParser::token::OP_TIMES); }
"("											{ return(nd::ExpressionParser::token::PAREN_OP); }
")"											{ return(nd::ExpressionParser::token::PAREN_CL); }
%%
