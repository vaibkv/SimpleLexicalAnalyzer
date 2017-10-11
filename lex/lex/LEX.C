              /* CONTAINS FUNCTIONS TO PERFORM LEXER OPERATIONS. */

#include "C:\tc\bin\lex\tabFun.h"
#include<stdio.h>

#define BUF_SIZE 100

#define ACTION1(tt) printf("\n %20s : %5d : %s",str_tok_id[tok_id], lex_lineno,lextext)
#define ACTION(tt) insert((tt), tok_id, lextext, lex_lineno);

FILE* lex_in =NULL;
FILE* lex_out =NULL;

simple_lexer()		//PERFORMS THE LEXER FUNCTION.
{
	char lextext[BUF_SIZE], ch;
	int lex_ptr, f_dot = 0, comment, lex_lineno=1;
	TOKEN_ID tok_id;

	while((ch=fgetc(lex_in)) != EOF)
	{

			lex_ptr = 0;

			/* TO RECOGNIZE IDENTIFERS & KEYWORDS */
			if( isalpha(ch) || ch== '_')
			{
					lextext[lex_ptr++] = ch;
					ch = fgetc(lex_in);
					while(ch=='_' || ch>='a' && ch<='z' || ch>='A' && ch<='Z'||ch>='0'&&ch<='9')
					{
						lextext[lex_ptr++] = ch;
						ch = fgetc(lex_in);
					}
					ungetc(ch, lex_in);
					lextext[lex_ptr] = '\0';

					if(iskeyword(lextext))
					{
						tok_id = KEYWORD;
						ACTION(_KEYWORD);
					}
					else
					{
						tok_id = ID;
						ACTION(_IDENTIFIER);
					}

			}

			/* TO RECOGNIZE THE LITERALS */
			else if( isdigit(ch))
			{
				lextext[lex_ptr++] = ch;
				ch = fgetc(lex_in);
				tok_id = LIT;

				while(isdigit(ch) || ch == '.')
				{
					if(isdigit(ch))
						lextext[lex_ptr++] = ch;

					else if(ch== '.' && !f_dot)
					{
						lextext[lex_ptr++] = ch;
						f_dot = 1;
					}
					else if(ch=='.')
					{
						printf("\n\t ***** Error: Invalid literal at LINE %d******\n",lex_lineno);
						exit(1);
					}
					ch = fgetc(lex_in);
				}
				ungetc(ch, lex_in);
				lextext[lex_ptr] ='\0';

				ACTION(_LITERAL);
			}

			else
			{
				switch(ch)
				{
					case '"':				/* TO RECOGNIZE STRING LITERALS */
							tok_id = STR_LIT;

							while(ch=fgetc(lex_in))
							{
								if(ch=='"' && lextext[ lex_ptr-1 ] != '\\')
									break;
								else if(ch=='"')
									lextext[lex_ptr++] = ch;
								else if(ch=='\n')
								{
									printf("\n Error: Invalid string literal at LINE: %d.\n",lex_lineno);
									exit(1);
								}
								else
									lextext[lex_ptr++] = ch;
							}

							lextext[lex_ptr]='\0';
							ACTION(_STR_LITERAL);
							break;

				case '+':				/* TO RECOGNIZE +, ++. += */
							lextext[lex_ptr] = ch, tok_id = PLUS;
							ch = fgetc(lex_in);
							if(ch == '+' || ch == '=')
							{
								lextext[lex_ptr++] = ch;
								if(ch == '+') tok_id=INCR;
								else tok_id=PLUS_EQU;
							}
							else
								ungetc(ch, lex_in);

							lextext[lex_ptr] = '\0';
							ACTION(_OPERATOR);
							break;

				case '-':				/* TO RECOGNIZE -,--,-= */
							lextext[lex_ptr] = ch;
							tok_id = MINUS;
							ch = fgetc(lex_in);

							if(ch == '-' || ch == '=')
							{
								lextext[lex_ptr++] = ch;
								if(ch == '-') tok_id=DECR;
								else tok_id=MINUS_EQU;
							}
							else
								ungetc(ch, lex_in);

							lextext[lex_ptr] = '\0';
							ACTION(_OPERATOR);
							break;

				case '*':				/* TO RECOGNIZE *, *= */
							lextext[lex_ptr] = ch;
							tok_id = MULT;
							ch = fgetc(lex_in);

							if(ch == '=')
								lextext[lex_ptr++] = ch, tok_id=MULT_EQU;
							else
								ungetc(ch, lex_in);

							lextext[lex_ptr] = '\0';
							ACTION(_OPERATOR);
							break;

				case '/':				/* TO RECOGNIZE /, /= *AND COMMENTS */
							comment = 0;
							lextext[lex_ptr++] = ch;
							tok_id = DIVISION;

							if((ch = fgetc(lex_in)) == '*')
							{
								comment = 1;
								do
								{
									while((ch=fgetc(lex_in)) != '*' && ch != EOF);
								}while((ch = fgetc(lex_in)) != '/' );
							}

							else
							{
								if((ch = fgetc(lex_in)) == '=')
									lextext[lex_ptr++] = ch, tok_id = DIV_EQU;
								else
									ungetc(ch, lex_in);

								lextext[lex_ptr] = '\0';
								ACTION(_OPERATOR);
							}

							break;

				case '<':				/* TO RECOGNIZE <, <=, << */
							lextext[lex_ptr++] = ch, tok_id = LT;

							if((ch = fgetc(lex_in)) == '<' || ch == '=')
							{
								lextext[lex_ptr++] = ch;
								if(ch == '<') tok_id=LS ;
								else tok_id=LT_EQU;
							}
							else
								ungetc(ch, lex_in);

							lextext[lex_ptr] = '\0';
							ACTION(_OPERATOR);

							break;

				case '>':				/* TO RECOGNIZE >, >=, >> */
							lextext[lex_ptr++] = ch, tok_id = GT;

							if((ch = fgetc(lex_in)) == '>' || ch == '=')
							{
								lextext[lex_ptr++] = ch;
								if (ch == '>')
									tok_id=RS;
								else
									tok_id=GT_EQU;
							}
							else
								ungetc(ch, lex_in);

							lextext[lex_ptr] = '\0';
							ACTION(_OPERATOR);

							break;

				case '=':				/* TO RECOGNIZE =, == */
							lextext[lex_ptr++] = ch, tok_id = EQU;

							if((ch = fgetc(lex_in)) == '=')
							{
								lextext[lex_ptr++] = ch,	tok_id=COND_EQU;
							}
							else
								ungetc(ch, lex_in);

							lextext[lex_ptr] = '\0';
							ACTION(_OPERATOR);
							break;

				case '!':				/*TO RECOGNISE !, !=*/
							lextext[lex_ptr++] = ch, tok_id = NOT;

							if((ch = fgetc(lex_in)) == '=')
							{
								lextext[lex_ptr++] = ch,	tok_id=NOT_EQU;
							}
							else
								ungetc(ch, lex_in);

							lextext[lex_ptr] = '\0';
							ACTION(_OPERATOR);
							break;

				case '{': 		lextext[lex_ptr++]=ch, tok_id=OP_F_BRC;
							lextext[lex_ptr]='\0';
							ACTION(_SPL_SYMBOL);
							break;

				case '}': 		lextext[lex_ptr++]=ch, tok_id=CL_F_BRC;
							lextext[lex_ptr]='\0';
							ACTION(_SPL_SYMBOL);
							break;

				case '[': 		lextext[lex_ptr++]=ch, tok_id=OP_S_BRC;
							lextext[lex_ptr]='\0';
							ACTION(_SPL_SYMBOL);
							break;

				case ']': 		lextext[lex_ptr++]=ch, tok_id=CL_S_BRC;
							lextext[lex_ptr]='\0';
							ACTION(_SPL_SYMBOL);
							break;

				case '(': 		lextext[lex_ptr++]=ch, tok_id=OP_BRC;
							lextext[lex_ptr]='\0';
							ACTION(_SPL_SYMBOL);
							break;

				case ')': 		lextext[lex_ptr++]=ch, tok_id=CL_BRC;
							lextext[lex_ptr]='\0';
							ACTION(_SPL_SYMBOL);
							break;

				case ':': 		lextext[lex_ptr++]=ch, tok_id=COLON;
							lextext[lex_ptr]='\0';
							ACTION(_SPL_SYMBOL);
							break;

				case ';': 		lextext[lex_ptr++]=ch, tok_id=TERM;
							lextext[lex_ptr]='\0';
							ACTION(_SPL_SYMBOL);
							break;

				case '#': 		lextext[lex_ptr++]=ch, tok_id=HASH;
							lextext[lex_ptr]='\0';
							ACTION(_SPL_SYMBOL);
							break;

				case '.': 		lextext[lex_ptr++]=ch, tok_id=DOT;
							lextext[lex_ptr]='\0';
							ACTION(_SPL_SYMBOL);
							break;

				case ',': 		lextext[lex_ptr++]=ch, tok_id=COMMA;
							lextext[lex_ptr]='\0';
							ACTION(_SPL_SYMBOL);
							break;

				case '&': 		lextext[lex_ptr++]=ch, tok_id=AMPERSAND;
							lextext[lex_ptr]='\0';
							ACTION(_SPL_SYMBOL);
							break;

				case '\n':		lextext[0]='\n';
							lextext[1]='\0';
							lex_lineno++;
							break;
				case '\t':
				case ' ':		while((ch=fgetc(lex_in))==' '||ch=='\t');
							ungetc(ch,lex_in);
							break;
				} /*END OF SWITCH*/
		}/* else */

	} /*END OF WHILE(ch=fgetc(lex_in)!=EOF) */

}// END OF lex()

int iskeyword(char *key_wrd)
{
	int i;

	for(i=0;i<32;i++)
		if(strcmp(key_wrd,key[i])==0)
			return 1;

	return 0;
}

main(int argc, char *argv[])
{
	int i;
	
	if(argc != 2 )
	{
		printf("\n Usage: %s <source_C_file> \n", argv[0]);
		exit(1);
	}

	if((lex_in = fopen(argv[1], "r")) == NULL)
	{
		printf("\n Error: Unable to open the source file.\n");
		exit(1);
	}

	simple_lexer();
	
	for(i=SYMBOL_TAB; i<=SPL_SYM_TAB; i++)
		display_table(i);
		
	printf("\n");
	fcloseall();
}
