%{
#include <stdio.h>
#include "lex.yy.c"
#include "cal.h"
ExprAST *p;
%}

%union {
    int val;
    ExprAST *ast;
}

%type <val> INTEGER
%type <ast> expr factor

%token BRACKET INTEGER PLUS MINUS TIMES DIVIDE MODULO LP RP 

%left PLUS MINUS
%left TIMES DIVIDE 
%left MODULO

%%

formula: 
    expr {printf("Expr_AST: \n"); std::vector<int> s; $1->print(s);};

expr: 
    expr PLUS expr {p = new ExprAST(PLUS); p->insert($1, $3); $$ = p;}
	| expr MINUS expr {p = new ExprAST(MINUS); p->insert($1, $3); $$ = p;}
	| expr TIMES expr {p = new ExprAST(TIMES); p->insert($1, $3); $$ = p;}
	| expr DIVIDE expr {p = new ExprAST(DIVIDE); p->insert($1, $3); $$ = p;}
	| expr MODULO expr {p = new ExprAST(MODULO); p->insert($1, $3); $$ = p;}
	| LP expr RP {p = new ExprAST(BRACKET); p->insert($2); $$ = p;}
    | factor {$$ = $1;}
	;

factor:
    INTEGER {p = new ExprAST($1); $$ = p;}
    ;

%%

int main()
{
	return yyparse();
} 

void yyerror(char* s)
{
	fprintf(stderr,"%s",s);
} 

int yywrap()
{
	return 1;
}