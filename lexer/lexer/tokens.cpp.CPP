# include "tokens.h"
# include "data_structure.cpp"


void install_keywords()
{
int what_happened;
char retry ;

for(int i=0 ; i<=31 ; i++)
{
what_happened = install_token(ansi_c[i],"keyword");
if(what_happened == -1)
{printf("\nError : Could not install the keyword %s",ansi_c[i]);
printf("\nRetry (y / n) ?");
scanf("%c",&retry);
if(retry == 'y' || retry == 'Y')
i--;
}
else ;

}
}


void install_std_io()
{
printf("\nstdio.h is an ANSI C standard header and its functions are currently being installed....");

int what_happened ;
char retry ;

for(int i=0;i<=25;i++)
{
what_happened = install_token(std_io[i],"function in stdio.h");
if(what_happened == -1)
{printf("\nError : Could not install the function %s",std_io[i]);
printf("\nRetry (y / n) ?");
scanf("%c",&retry);
if(retry == 'y' || retry == 'Y')
i--;
}
else ;
}
}


void install_c_type()
{
printf("\nctype.h is an ANSI C standard header and its functions are currently being installed....");

int what_happened ;
char retry ;

for(int i=0;i<=7;i++)
{
what_happened = install_token(c_type[i],"function in ctype.h");
if(what_happened == -1)
{printf("\nError : Could not install the function %s",c_type[i]);
printf("\nRetry (y / n) ?");
scanf("%c",&retry);
if(retry == 'y' || retry == 'Y')
i--;
}
else ;
}
}


void install_str_ing()
{
printf("\nstring.h is an ANSI C standard header and its functions are currently being installed....");

int what_happened ;
char retry ;

for(int i=0;i<=5;i++)
{
what_happened = install_token(str_ing[i],"function in string.h");
if(what_happened == -1)
{printf("\nError : Could not install the function %s",str_ing[i]);
printf("\nRetry (y / n) ?");
scanf("%c",&retry);
if(retry == 'y' || retry == 'Y')
i--;
}
else ;
}
}


void install_ma_th()
{
printf("\nmath.h is an ANSI C standard header and its functions are currently being installed....");

int what_happened ;
char retry ;

for(int i=0;i<=18;i++)
{
what_happened = install_token(ma_th[i],"function in math.h");
if(what_happened == -1)
{printf("\nError : Could not install the function %s",ma_th[i]);
printf("\nRetry (y / n) ?");
scanf("%c",&retry);
if(retry == 'y' || retry == 'Y')
i--;
}
else ;
}
}



void install_std_lib()
{
printf("\nstdlib.h is an ANSI C standard header and its functions are currently being installed....");


int what_happened ; 
char retry ;

for(int i=0;i<=11;i++)
{
what_happened = install_token(std_lib[i],"function in stdlib.h");
if(what_happened == -1)
{printf("\nError : Could not instll the function %s",std_lib[i]);
printf("\nRetry (y / n) ?");
scanf("%c",&retry);
if(retry == 'y' || retry == 'Y')
i--;
}
else ;
}
}

void install_op()
{
install_token("+","Addition operator");
install_token("++","Increment operator");
install_token("+=","Addition-Assignment operator");
install_token("-","Subtraction operator");
install_token("--","Decrement operator");
install_token("-=","Subtraction-Assignment operator");
install_token("*","Multiplication operator");
install_token("*=","Multiplication-Assignment operator");
install_token("/","Division operator");
install_token("/=","Division-Assignment operator");
install_token("<","Lesser than");
install_token("<=","Lesser than or equal to");
install_token("<<","Left shift operator");
install_token(">","Greater than");
install_token(">=","Greater than or equal to");
install_token(">>","Right shift operator");
install_token("=","Assignment operator");
install_token("==","Equal to");
install_token("!","NOT");
install_token("!=","Not equal to");
install_token("&&","AND operator");
install_token("&","AMPERSAND");
install_token("||","OR operator");
install_token("%","Modulus");
install_token("%=","Moddulus-Assignment operator");

}

