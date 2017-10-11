
/* DEFINES TOKEN TYPES, TOKEN ID, STRING EQUIVALENT TOKEN ID FOR PRINTING */


#define _TOKENS_H

typedef enum
{
	_IDENTIFIER,
	_KEYWORD,
	_LITERAL,
	_STR_LITERAL,
	_OPERATOR,
	_SPL_SYMBOL
}TOKEN_TYPE;

typedef enum
{
	ID,
	LIT,
	STR_LIT,
	OP_BRC,
	CL_BRC,
	OP_F_BRC,
	CL_F_BRC,
	OP_S_BRC,
	CL_S_BRC,
	TERM,
	COMMA,
	EQU,
	COND_EQU,
	PLUS,
	PLUS_EQU,
	INCR,
	MINUS,
	MINUS_EQU,
	DECR,
	DIVISION,
	DIV_EQU,
	MODULUS,
	MOD_EQU,
	CARET,
	MULT,
	MULT_EQU,
	AMPERSAND,
	COLON,
	QUESTION,
	HASH,
	NOT,
	NOT_EQU,
	TILDE,
	GT,
	GT_EQU,
	LT,
	LT_EQU,
	LS,
	RS,
	DOT,
	KEYWORD
}TOKEN_ID;

char *str_tok_id[] ={
	"ID",
	"LIT",
	"STR_LITERAL",		// ".........", ANYTHING BETWEEN " & "
	"OP_BRC",		// (
	"CL_BRC",			// )
	"OP_F_BRC",		// {
	"CL_F_BRC",		// }
	"OP_S_BRC",		// [
	"CL_S_BRC",		// ]
	"TERM",			// ;
	"COMMA",		// ,
	"EQUAL",			// =
	"COND_EQU",		//==
	"PLUS",			// +
	"PLUS_EQU",		//+=
	"INCR",			//++
	"MINUS",			// -
	"MINUS_EQU",	// -=
	"DECR",			//--
	"DIVISION",		// /
	"DIV_EQU",		// /=
	"MODULUS",		// %
	"MOD_EQU",		// %=
	"CARET",			// ^
	"MULT",			// *
	"MULT_EQU",		// *=
	"AMPERSAND",	// &
	"COLON",			// :
	"QUESTION",		// ?
	"HASH",			// #
	"NOT",			// !
	"NOT_EQU",		// !=
	"TILDE",			// ~
	"GREATER_THAN", //>
	"GREATER_EQU",	//>=
	"LESSER_THAN",	//<
	"LESSER_EQU",	//<=
	"LEFT_SHIFT",		//<<
	"RIGHT_SHIFT",		//>>
	"DOT",
	"KEYWORD"		// int, float, void,....
};
