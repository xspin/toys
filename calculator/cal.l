%{
#include<string.h>
#include "y.tab.h"
%}


numbers ([0-9])+
plus "+"
minus "-"
times "*"
divide "/"
modulo "%"
lp "("
rp ")"
chars [A-Za-z]
words {chars}+
delim [ \n\t]
ws {delim}*


%%
{numbers} {
    sscanf(yytext, "%d", &yylval.val);
    return INTEGER;
}
{plus} {return PLUS;}
{minus} {return MINUS;}
{times} {return TIMES;}
{divide} {return DIVIDE;}
{modulo} {return MODULO;}
{lp} {return LP;}
{rp} {return RP;}
{ws}       ;
. {printf("Error");exit(1);}  
%%
