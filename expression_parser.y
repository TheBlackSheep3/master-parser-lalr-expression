%skeleton "lalr1.cc"
%require	"3.0"
%defines
%define api.namespace {nd}
%define api.parser.class {ExpressionParser}
%code requires {
	namespace nd {
		class ExpressionScanner;
	}
}

%parse-param { ExpressionScanner& scanner }

%define api.value.type variant
%define parse.assert

%token <std::string>	ID
%token <int>					LIT
%token								OP_PLUS
%token								OP_TIMES
%token								PAREN_OP
%token								PAREN_CL

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

void nd::ExpressionParser::error(location_type const& loc, std::string const& err_message) {
	std::cerr << "Error: " << err_message << " at " << loc << "\n";
}
