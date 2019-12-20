#define INTEGER 257
#define BRACKET 258
#define PLUS 259
#define MINUS 260
#define TIMES 261
#define DIVIDE 262
#define MODULO 263
#define LP 264
#define RP 265
#include "cal.h"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
    int val;
    ExprAST *ast;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
