/* CONTAINS FUNCTION FOR SEARCHING THE TABLES AND FOR ADDING THE ENTRY TO THE
TABLES. */
#define _TABFUN_H

#ifndef _DATAST_H
#include "C:\tc\bin\lex\dataSt.h"
#endif

#ifndef _MALLOC_H
#include <malloc.h>
#include <stdio.h>
#endif

typedef enum
{
	SYMBOL_TAB,
	ID_TAB,
	KEYWORD_TAB,
	LITERAL_TAB,
	STR_LIT_TAB,
	OPERATOR_TAB,
	SPL_SYM_TAB
}TABLE_TYPE;

/* THIS FUNCTION IS USED TO ADD THE TOKEN_ID INTO THE SYMBOL TABLE & CHAR *
(VALUE) TO THIER RESPECTIVE TABLES */
void insert(TOKEN_TYPE, TOKEN_ID, char *, int);

/* THIS FUNCTION IS USED TO ADD THE CHAR * (VALUE) INTO THEIR RESPECTIVE
TABLE. */
void* insert_table(TOKEN_TYPE, char *);

/* THIS FUNCTION IS USED TO SEARCH FOR CHAR * (VALUE) IN THE TABLE. IF THE
"VALUE" IS PRESENT THEN IT RETURNS THE ADDRESS OF THE ENTRY. ELSE RETURNS
"NULL" */
void* search(TOKEN_TYPE, char *);

/* THIS FUNCTION IS USED TO UPDATE THE SYMBOL TABLE FOR ANY NEW ENTRY. */
int insert_symbol_table(TOKEN_ID, void *, int);

void init_tab();

void display_table(TABLE_TYPE);
/* EXPLANATION: WORKING

1. Search the table whether the "token" is already present in the table using
   search().

2. if the entry is found, then the address of the entry in the table is
   returned. This value is then used to add the "token_id" into the
   "symbol_table", using insert_symbol_table().

	* if the entry is not found,then the new entry is made in their respective
	  table usint insert_table() & the address of the new entry is returned, so
  	  that the "token_id" can be entered into the symbol table using
	  insert_symbol_table().
*/



/* THIS FUNCTION IS USED TO ADD THE TOKEN_ID INTO THE SYMBOL TABLE & CHAR *
(VALUE) TO THIER RESPECTIVE TABLES */

void insert(TOKEN_TYPE tok_typ, TOKEN_ID tok_id, char *value, int lineno)
{
	void *res;

	if( (res = search(tok_typ, value)) == NULL)
		res = insert_table(tok_typ, value);

	insert_symbol_table(tok_id, res,lineno);

}

/* THIS FUNCTION IS USED TO ADD THE CHAR * (VALUE) INTO THEIR RESPECTIVE TABLE.
*/
void* insert_table(TOKEN_TYPE tok_typ, char *value)
{
	void *location;

	switch(tok_typ)
	{
		case _IDENTIFIER:	if(tab_id.first == NULL)
					{
						tab_id.first = (N_ID *) malloc(sizeof(N_ID));
						if(tab_id.first == NULL)
						{ printf("\n Error: Cannot allocate the memory"); exit(0); }
						tab_id.first->value = (char*) malloc(strlen(value));
						strcpy(tab_id.first->value, value);
						tab_id.first->next = NULL;
						tab_id.last = tab_id.first;
					}
					else
					{
						tab_id.last->next = (N_ID *) malloc(sizeof(N_ID));
						tab_id.last = tab_id.last->next;
						tab_id.last->value = (char*) malloc(strlen(value));
						strcpy(tab_id.last->value, value);
						tab_id.last->next = NULL;
					}
					location = (void *) tab_id.last;
					break;

		case _KEYWORD:		if(tab_keyword.first == NULL)
					{
						tab_keyword.first = (N_KEYWORD *) malloc(sizeof(N_KEYWORD));
						tab_keyword.first->value = (char*) malloc(strlen(value));
						strcpy(tab_keyword.first->value, value);
						tab_keyword.first->next = NULL;
						tab_keyword.last = tab_keyword.first;
					}
					else
					{
						tab_keyword.last->next = (N_KEYWORD*) malloc(sizeof(N_KEYWORD));
						tab_keyword.last = tab_keyword.last->next;
						tab_keyword.last->value = (char*) malloc(strlen(value));
						strcpy(tab_keyword.last->value, value);
						tab_keyword.last->next = NULL;
					}
					location = (void *) tab_keyword.last;
					break;

		case _LITERAL:		if(tab_lit.first == NULL)
					{
						tab_lit.first = (N_LIT *) malloc(sizeof(N_LIT));
						tab_lit.first->value = (char*) malloc(strlen(value));
						strcpy(tab_lit.first->value, value);
						tab_lit.first->next = NULL;
						tab_lit.last = tab_lit.first;
					}
					else
					{
						tab_lit.last->next = (N_LIT *) malloc(sizeof(N_LIT));
						tab_lit.last = tab_lit.last->next;
						tab_lit.last->value = (char*) malloc(strlen(value));
						strcpy(tab_lit.last->value, value);
						tab_lit.last->next = NULL;
					}
					location = (void *) tab_lit.last;
					break;

		case _STR_LITERAL:	if(tab_str_lit.first == NULL)
					{
						tab_str_lit.first = (N_STR_LIT *) malloc(sizeof(N_STR_LIT));
						tab_str_lit.first->value = (char*) malloc(strlen(value));
						strcpy(tab_str_lit.first->value, value);
						tab_str_lit.first->next = NULL;
						tab_str_lit.last = tab_str_lit.first;
					}
					else
					{
						tab_str_lit.last->next = (N_STR_LIT *) malloc(sizeof(N_STR_LIT));
						tab_str_lit.last = tab_str_lit.last->next;
						tab_str_lit.last->value = (char*) malloc(strlen(value));
						strcpy(tab_str_lit.last->value, value);
						tab_str_lit.last->next = NULL;
					}
					location = (void *) tab_str_lit.last;
					break;

		case _SPL_SYMBOL:	if(tab_spl_sym.first == NULL)
					{
						tab_spl_sym.first = (N_SPL_SYM *) malloc(sizeof(N_SPL_SYM));
						tab_spl_sym.first->value = (char*) malloc(strlen(value));
						strcpy(tab_spl_sym.first->value, value);
						tab_spl_sym.first->next = NULL;
						tab_spl_sym.last = tab_spl_sym.first;
					}
					else
					{
						tab_spl_sym.last->next = (N_SPL_SYM *) malloc(sizeof(N_SPL_SYM));
						tab_spl_sym.last = tab_spl_sym.last->next;
						tab_spl_sym.last->value = (char*) malloc(strlen(value));
						strcpy(tab_spl_sym.last->value, value);
						tab_spl_sym.last->next = NULL;
					}
					location = (void *) tab_spl_sym.last;
					break;

		case _OPERATOR:		if(tab_oper.first == NULL)
					{
						tab_oper.first = (N_OPER *) malloc(sizeof(N_OPER));
						tab_oper.first->value = (char*) malloc(strlen(value));
						strcpy(tab_oper.first->value, value);
						tab_oper.first->next = NULL;
						tab_oper.last = tab_oper.first;
					}
					else
					{
						tab_oper.last->next = (N_OPER *) malloc(sizeof(N_OPER));
						tab_oper.last = tab_oper.last->next;
						tab_oper.last->value = (char*) malloc(strlen(value));
						strcpy(tab_oper.last->value, value);
						tab_oper.last->next = NULL;
					}
					location = (void *) tab_oper.last;
					break;
	}
}

/* THIS FUNCTION IS USED TO SEARCH FOR CHAR * (VALUE) IN THE TABLE. IF THE
"VALUE" IS PRESENT THEN IT RETURNS THE ADDRESS OF THE ENTRY. ELSE RETURNS "NULL"
*/

void* search(TOKEN_TYPE tok_typ, char *value)
{
	N_ID *ptr_id = NULL;
	N_LIT *ptr_lit = NULL;
	N_STR_LIT *ptr_str = NULL;
	N_KEYWORD *ptr_key = NULL;
	N_SPL_SYM *ptr_spl = NULL;
	N_OPER *ptr_op = NULL;

	switch(tok_typ)
	{
		case _IDENTIFIER:
				if(tab_id.first == NULL) { return NULL; }

				for(ptr_id = tab_id.first; ptr_id != NULL; ptr_id = ptr_id->next)
					/* IF IDENTIFIER FOUND, RETURN ITS LOCATION VALUE. */
					if(strcmp(ptr_id->value, value) == 0) return (void*)ptr_id;

				return NULL; /* IDENTIFIER NOT FOUND IN THE TABLE. */
				break;

		case _KEYWORD:
				if(tab_keyword.first == NULL) { return NULL; }

				for(ptr_key = tab_keyword.first; ptr_key != NULL; ptr_key = ptr_key->next)
					if(strcmp(ptr_key->value, value) == 0) return (void*)ptr_key;

				return NULL;
				break;

		case _LITERAL:
				if(tab_lit.first == NULL) { return NULL; }

				for(ptr_lit = tab_lit.first; ptr_lit != NULL; ptr_lit = ptr_lit->next)
					if(strcmp(ptr_lit->value, value) == 0) return (void*)ptr_lit;

				return NULL;
				break;

		case _STR_LITERAL:
				if(tab_str_lit.first == NULL) { return NULL; }

				for(ptr_str = tab_str_lit.first; ptr_str != NULL; ptr_str = ptr_str->next)
					if(strcmp(ptr_str->value, value) == 0) return (void*)ptr_str;

				return NULL;
				break;

		case _SPL_SYMBOL:
				if(tab_spl_sym.first == NULL) { return NULL; }

				for(ptr_spl = tab_spl_sym.first; ptr_spl != NULL; ptr_spl = ptr_spl->next)
					if(strcmp(ptr_spl->value, value) == 0) return (void*)ptr_spl;

				return NULL;
				break;
				
		case _OPERATOR:
				if(tab_oper.first == NULL) { return NULL; }

				for(ptr_op = tab_oper.first; ptr_op != NULL; ptr_op = ptr_op->next)
					if(strcmp(ptr_op->value, value) == 0) return (void*)ptr_op;

				return NULL;
				break;
	}
}

/* THIS FUNCTION IS USED TO UPDATE THE SYMBOL TABLE FOR ANY NEW ENTRY. */

int insert_symbol_table(TOKEN_ID tok_id, void *loc_ptr, int line)
{

	if(tab_sym.first != NULL)
	{
		tab_sym.last->next = (N_SYM *) malloc(sizeof(N_SYM));
		tab_sym.last = tab_sym.last->next;

		tab_sym.last->tok_id = tok_id;
		tab_sym.last->val_ptr = loc_ptr;
		tab_sym.last->line = line;
		tab_sym.last->next = NULL;

	}
	else
	{
		tab_sym.first = (N_SYM *) malloc(sizeof(N_SYM));
		tab_sym.first->tok_id = tok_id;
		tab_sym.first->val_ptr = loc_ptr;
		tab_sym.first->line = line;
		tab_sym.first->next = NULL;
		tab_sym.last = tab_sym.first;
	}
}

/* INITIALIZES ALL THE TABLES FIRST & LAST POINTER TO NULL VALUE */
void init_tab()
{

	printf("\n Inside init_tab()");
	tab_sym.first = NULL; tab_sym.last = NULL;
	tab_lit.first = NULL; tab_lit.last = NULL;
	tab_str_lit.first = NULL; tab_str_lit.last = NULL;
	tab_keyword.first = NULL; tab_keyword.last = NULL;
	tab_oper.first = NULL; tab_oper.last = NULL;
	tab_spl_sym.first = NULL; tab_spl_sym.last = NULL;
	tab_id.first = NULL; tab_id.last = NULL;
}

void display_table(TABLE_TYPE tt)
{
	N_SYM *tmp_sym = NULL;
	N_ID *tmp_id = NULL;
	N_SPL_SYM *tmp_spl = NULL;
	N_OPER *tmp_oper = NULL;
	N_LIT *tmp_lit = NULL;
	N_STR_LIT *tmp_str = NULL;
	N_KEYWORD *tmp_key = NULL;
	
switch(tt)
{
	case SYMBOL_TAB:	
	printf("\n--------------------------------");
	printf("\n   SYMBOL TABLE                 \\");
	printf("\n----------------------------------------------------\n");
	printf("%19s  | %5s  |  %s","TOKEN ID","LINE","Location          |");
	printf("\n----------------------------------------------------\n");
		for(tmp_sym = tab_sym.first; tmp_sym != NULL; tmp_sym = tmp_sym->next)
	printf("\n%20s : %5d : %d",str_tok_id[tmp_sym->tok_id], tmp_sym->line, tmp_sym->val_ptr);
	printf("\n---------------------------------------------------|\n");
	break;

	case ID_TAB:
	printf("\n\n--------------------------------");
	printf("\n   IDENTIFIER TABLE             \\");
	printf("\n-------------------------------------------------------------------\n");
	printf("%10s  | %s","Location","Id value                                            |");
	printf("\n-------------------------------------------------------------------\n");
		for(tmp_id = tab_id.first; tmp_id != NULL; tmp_id = tmp_id->next)
			printf("\n%10d : %s",tmp_id, tmp_id->value);
	printf("\n------------------------------------------------------------------|\n");
	break;

	case KEYWORD_TAB:		
	printf("\n\n--------------------------------");
	printf("\n   KEYWORD TABLE                \\");
	printf("\n-------------------------------------------------------------------\n");
	printf("%10s  | %s","Location","Keyword value                                       |");
	printf("\n-------------------------------------------------------------------\n");
		for(tmp_key = tab_keyword.first; tmp_key != NULL; tmp_key = tmp_key->next)
			printf("\n%10d : %s",tmp_key, tmp_key->value);
	printf("\n------------------------------------------------------------------|\n");
	break;

	
	case LITERAL_TAB:
	printf("\n\n--------------------------------");
	printf("\n   LITERAL TABLE                \\");
	printf("\n-------------------------------------------------------------------\n");
	printf("%10s  | %s","Location","Literal value                                       |");
	printf("\n-------------------------------------------------------------------\n");
		for(tmp_lit = tab_lit.first; tmp_lit != NULL; tmp_lit = tmp_lit->next)
			printf("\n%10d : %s",tmp_lit, tmp_lit->value);
	printf("\n------------------------------------------------------------------|\n");
	break;

	case STR_LIT_TAB:
	printf("\n\n--------------------------------");
	printf("\n   STRINGS TABLE                \\");
	printf("\n-------------------------------------------------------------------\n");
	printf("%10s  | %s","Location","String value                                        |");
	printf("\n-------------------------------------------------------------------\n");
		for(tmp_str = tab_str_lit.first; tmp_str != NULL; tmp_str = tmp_str->next)
			printf("\n%10d : %s",tmp_str, tmp_str->value);
	printf("\n------------------------------------------------------------------|\n");
	break;

	case OPERATOR_TAB:
	printf("\n\n--------------------------------");
	printf("\n   OPERATOR TABLE               \\");
	printf("\n-------------------------------------------------------------------\n");
	printf("%10s  | %s","Location","Operator value                                      |");
	printf("\n-------------------------------------------------------------------\n");
		for(tmp_oper = tab_oper.first; tmp_oper != NULL; tmp_oper = tmp_oper->next)
			printf("\n%10d : %s",tmp_oper, tmp_oper->value);
	printf("\n------------------------------------------------------------------|\n");
	break;

	case SPL_SYM_TAB:
	printf("\n\n--------------------------------------");
	printf("\n   SPECIAL SYMBOL TABLE               \\");
	printf("\n-------------------------------------------------------------------\n");
	printf("%10s  | %s","Location","Special symbol value                                |");
	printf("\n-------------------------------------------------------------------\n");
		for(tmp_spl = tab_spl_sym.first; tmp_spl != NULL; tmp_spl = tmp_spl->next)
			printf("\n%10d : %s",tmp_spl, tmp_spl->value);
	printf("\n------------------------------------------------------------------|\n");
	break;

} // END OF SWITCH STATEMENT
}


