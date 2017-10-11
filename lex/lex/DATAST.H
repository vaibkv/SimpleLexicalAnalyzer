/* CONTAINS THE DATA STRUCTURE FOR ALL THE ELEMENTS OF THE LEXICAL ANALYZER LIKE
KEYWORD TABLE, SYMBOL TABLE, LITERAL TABLE, STRING LITERAL TABLE.*/

//CONDITIONAL INCLUSION OF"tokens.h"
#define _DATAST_H

#ifndef _TOKENS_H
#include "C:\tc\bin\lex\tokens.h"
#endif

/* IDENTIFIER */
typedef struct identifier
{
	char *value;
	struct identifier *next;
}N_ID;

/* IDENTIFIER TABLE */
typedef struct
{
	N_ID *first;
	N_ID *last;
}ID_TABLE;

/* SPECIAL SYMBOLS LIKE *, {, }, ;, ,, +, -, ..... */
typedef struct spl_sym
{
	char *value;
	struct spl_sym *next;
}N_SPL_SYM;

/* SPECIAL SYMBOL TABLE */
typedef struct
{
	N_SPL_SYM* first;
	N_SPL_SYM* last;
}SPL_SYMBOL_TABLE;

/* KEYWORD NODE */
typedef struct keyword
{
	char *value;
	struct keyword *next;
}N_KEYWORD;

/* KEYWORD TABLE. */
typedef struct
{
	N_KEYWORD *first;
	N_KEYWORD *last;
}KEYWORD_TABLE;

/* STRING LITERAL NODE */
typedef struct str_lit
{
	char *value;
	struct str_lit *next;
}N_STR_LIT;

/* STRING LITERAL TABLE. */
typedef struct
{
	N_STR_LIT *first;
	N_STR_LIT *last;
}STR_LIT_TABLE;

/* LITERAL NODE */
typedef struct lit
{
	char *value;
	struct lit *next;
}N_LIT;

/* LITERAL TABLE. */
typedef struct
{
	N_LIT *first;
	N_LIT *last;
}LIT_TABLE;

/* SYMBOL TABLE NODE */
typedef struct symbol
{
	TOKEN_ID tok_id;
	void *val_ptr;
	int line;
	struct symbol *next;
}N_SYM;

/* SYMBOL TABLE */
typedef struct
{
	N_SYM *first;
	N_SYM *last;
}SYMBOL_TABLE;

/* OPERATOR NODE */
typedef struct oper
{
	char *value;
	struct oper *next;
}N_OPER;

/* OPERATOR TABLE. */
typedef struct
{
	N_OPER *first;
	N_OPER *last;
}OP_TABLE;

/* GLOBAL DECLARATION OF TABLES */
SYMBOL_TABLE tab_sym;
LIT_TABLE tab_lit;
STR_LIT_TABLE tab_str_lit;
KEYWORD_TABLE tab_keyword;
OP_TABLE tab_oper;
SPL_SYMBOL_TABLE tab_spl_sym;
ID_TABLE tab_id;

// 32 KEYWORDS OF C PROGRAMMING LANGUAGE
char *key[]= {
	"auto",
	"break",
	"case",
	"char",
	"const",
	"continue",
	"default",
	"do",
	"double",
	"else",
	"enum",
	"extern",
	"float",
	"far",
	"for",
	"goto",
	"if",
	"int",
	"long",
	"near",
	"register",
	"return",
	"short",
	"signed",
	"static",
	"struct",
	"switch",
	"typedef",
	"union",
	"unsigned",
	"void",
	"while"
};
