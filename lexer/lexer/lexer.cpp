# include "lexer.h"


void lexer()
{
   node *p;
   FILE *fp;
   char lex_text[80];
   char another,ch ;
   int flag;
   int dot_flag = 0;
   int comment_flag = 0;
   int lex_ptr = 0;
   int line_no = 1;

   fp = fopen("INPUT_FILE.C","r");

   if(fp == NULL)
   {
    printf("\nError : Unable to open file INPUT_FILE.C for reading");
    another = getchar();
    exit(0);
   }

   while((ch = fgetc(fp)) != EOF )
   {
     lex_ptr = 0;

       if(isalpha(ch) || ch == '_')
       {
        lex_text[lex_ptr++] = ch;
        ch = fgetc(fp);

       while(isalnum(ch) || ch == '_')
       {
        lex_text[lex_ptr++] = ch;
        ch = fgetc(fp);
       }
    ungetc(ch,fp);
    lex_text[lex_ptr++] = '\0';

    for(int i=0 ;i<=5;i++)
    { flag = 0 ;
      if(!strcmp(lex_text,headers[i]) && !flag)
      {switch(i)
       {
        case 0 : install_std_io() ; flag = 1 ; break ;
        case 1 : install_c_type() ; flag = 1 ; break ;
        case 2 : install_str_ing() ; flag = 1 ; break ;
        case 3 : install_ma_th() ; flag = 1 ; break ;
        case 4 : install_std_lib() ; flag = 1 ; break ;
        case 5 : printf("\nLINE NO. = %d\tTOKEN = %s\tTOKEN TYPE = main function\tMEMORY ADDRESS = %u",line_no,headers[5],&headers[5]); flag = 1; break ; 
       }

      }

    }

      if(flag == 0)
      {
       p = lookup(lex_text);

       if(p != NULL)
       {
        printf("\nLINE NO. = %d\tTOKEN = %s\tTOKEN TYPE = %s\tMEMORY ADDRESS = %u",line_no,p->token,p->token_type,p);
        lex_ptr = 0;
       }

       else
       {
         printf("\nLINE NO. = %d\tTOKEN = %s\tTOKEN TYPE = IDENTIFIER\tMEMORY ADDRESS = %u",line_no,lex_text,&lex_text);
         lex_ptr = 0;
       }
      }
    }

else if(isdigit(ch))
{
lex_text[lex_ptr++] = ch;
ch = fgetc(fp);

while(isdigit(ch) || ch == '.')
{
if(isdigit(ch))
lex_text[lex_ptr++] = ch ;

else if(ch == '.' && !dot_flag)
{
lex_text[lex_ptr++] = ch;
dot_flag = 1;
}

else if(ch == '.')
{
printf("\nError : Invalid literal at line number %d",line_no);
break ;
}

ch = fgetc(fp);
}

ungetc(ch,fp);
lex_text[lex_ptr] = '\0';
 
if(dot_flag == 1)
{printf("\nLINE NO. = %d\tTOKEN = %s\tTOKEN TYPE = Numeric Float literal\tMEMORY ADDRESS = %u",line_no,lex_text,&lex_text);
lex_ptr = 0;
}

else 
{
printf("\nLINE NO. = %d\tTOKEN = %s\tTOKEN TYPE = Numeric Integer literal\tMEMORY ADDRESS = %u",line_no,lex_text,&lex_text);
lex_ptr = 0;
}

}


else
{
     switch(ch)
     {
       case '"' : while(ch = fgetc(fp))
                 {
                 if(ch=='"' && lex_text[ lex_ptr-1 ] != '\\')
                 break ;

                 else if(ch == '"')
                 ex_text[lex_ptr++] = ch;

                 else if(ch == '\n')
                 {
                  printf("\nError : Invalid string literal at line no %d",line_no);
                  another = getchar ();
                  exit(0);
                 }
                 else
                 lex_text[lex_ptr++] = ch ;
                 }
                 lex_text[lex_ptr] = '\0';
                 printf("\nLINE NO. = %d\tTOKEN = %s\tTOKEN TYPE = String literal\tMEMORY ADDRESS = %u",line_no,lex_text,&lex_text);
l                lex_ptr = 0;
                 break ;

        case '+' : lex_text[lex_ptr++] = ch;
                  ch = fgetc(fp);
                  if(ch == '+' || ch == '=')
                  lex_text[lex_ptr++] = ch;
                  else
                  ungetc(ch,fp);
                  lex_text[lex_ptr] ='\0';
                  p = lookup(lex_text);
                  if(p != NULL)
                  {
                   printf("\nLINE NO. = %d\tTOKEN = %S\tTOKEN TYPE = %s\tMEMORY ADDRESS = %u",line_no,p->token,p->token_type,p);
                  lex_ptr = 0;
                  }
                  break ; 

        case '-' : lex_text[lex_ptr++] = ch;
                   ch = fgetc(fp);
                   if(ch == '-' || ch == '=')
                   lex_text[lex_ptr++] = ch;
                   else
                   ungetc(ch,fp);
                   lex_text[lex_ptr] = '\0';
                   p = lookup(lex_text);
                   if(p != NULL)
                   {
                   printf("\nLINE NO. = %d\tTOKEN = %S\tTOKEN TYPE = %s\tMEMORY ADDRESS = %u",line_no,p->token,p->token_type,p);
                  lex_ptr = 0;
                  }
                  break ; 

        case '*': lex_text[lex_ptr++] = ch;
                  ch = fgetc(fp);
                  if(ch == '=')
                  lex_text[lex_ptr++] = ch;
                  else
                  ungetc(ch,fp);
                  lex_text[lex_ptr] = '\0';
                  p = lookup(lex_text);
                  if(p != NULL)
                  {
                   printf("\nLINE NO. = %d\tTOKEN = %S\tTOKEN TYPE = %s\tMEMORY ADDRESS = %u",line_no,p->token,p->token_type,p);
                  lex_ptr = 0;
                  }
                  break ; 

case '/': comment_flag = 0;
lex_text[lex_ptr++] = ch;

if((ch = fgetc(fp)) == '*')
{
comment_flag = 1;
do
{
while((ch=fgetc(fp)) != '*' && ch != EOF);
}while((ch=fgetc(fp)) != '/');

printf("\nComment at line no %d",line_no);
}

else
{
ungetc(ch,fp);
if((ch = fgetc(fp)) == '=')
lex_text[lex_ptr++] = ch;

else 
ungetc(ch,fp);

lex_text[lex_ptr] = '\0' ;

p = lookup(lex_text);
printf("\nLINE NO. = %d\tTOKEN = %s\TOKEN TYPE = %s\tMEMORY ADDRESS = %u",line_no,p->token,p->token_type,p);
lex_ptr = 0;
}

break ;

case '<' : lex_text[lex_ptr++] = ch;

if((ch = fgetc(fp)) == '<' || ch == '=')

lex_text[lex_ptr++] = ch;

else
ungetc(ch,fp);
lex_text[lex_ptr] = '\0';
p = lookup(lex_text) ; 
printf("\nLINE NO. = %d\tTOKEN = %s\TOKEN TYPE = %s\tMEMORY ADDRESS = %u",line_no,p->token,p->token_type,p);
lex_ptr = 0;


break ;

case '=': lex_text[lex_ptr++] = ch;
 
if((ch = fgetc(fp)) == '=')
lex_text[lex_ptr++] = ch;

else 
ungetc(ch,fp);
lex_text[lex_ptr] = '\0';
p = lookup(lex_text) ; 
printf("\nLINE NO. = %d\tTOKEN = %s\TOKEN TYPE = %s\tMEMORY ADDRESS = %u",line_no,p->token,p->token_type,p);
lex_ptr = 0;


break ;

case '!': lex_text[lex_ptr++] = ch;
 
if((ch = fgetc(fp)) == '=')
lex_text[lex_ptr++] = ch;

else 
ungetc(ch,fp);
lex_text[lex_ptr] = '\0';
p = lookup(lex_text) ; 
printf("\nLINE NO. = %d\tTOKEN = %s\TOKEN TYPE = %s\tMEMORY ADDRESS = %u",line_no,p->token,p->token_type,p);
lex_ptr = 0;


break ;

case '&' : lex_text[lex_ptr++] = ch ;
if((ch = fgetc(fp)) == '&')
lex_text[lex_ptr++] = ch;
else
ungetc(ch,fp);
lex_text[lex_ptr] = '\0';
p = lookup(lex_text) ; 
printf("\nLINE NO. = %d\tTOKEN = %s\TOKEN TYPE = %s\tMEMORY ADDRESS = %u",line_no,p->token,p->token_type,p);
lex_ptr = 0;


break ;

case '|' : lex_text[lex_ptr++] = ch ;
if((ch = fgetc(fp)) == '|')
lex_text[lex_ptr++] = ch;
else
ungetc(ch,fp);
lex_text[lex_ptr] = '\0';
p = lookup(lex_text) ; 
printf("\nLINE NO. = %d\tTOKEN = %s\TOKEN TYPE = %s\tMEMORY ADDRESS = %u",line_no,p->token,p->token_type,p);
lex_ptr = 0;


break ;

case '%' : lex_text[lex_ptr++] = ch;
if((ch = fgetc(fp)) == '=')
lex_text[lex_ptr++] = ch;
else
ungetc(ch,fp);
lex_text[lex_ptr] = '\0';
p = lookup(lex_text) ; 
printf("\nLINE NO. = %d\tTOKEN = %s\TOKEN TYPE = %s\tMEMORY ADDRESS = %u",line_no,p->token,p->token_type,p);
lex_ptr = 0;


break ;

case '{' :
case '}' :
case '[' :
case ']' :
case '(' :
case ')' :
case ':' :
case '#' :
case '.' :
case ';' :
case ',' :
printf("\nLINE NO. = %d\tTOKEN = %c\tTOKEN TYPE = Special Symbol\tMEMORY ADDRESS = %u",line_no,ch,&ch);
break ;		

case '\n' :line_no++;
break ;

case '\t' :
case ' ' :
while((ch = fgetc(fp)) == ' ' || ch == '\t')  ;
ungetc(ch,fp);
break ;

}



}

}
}							