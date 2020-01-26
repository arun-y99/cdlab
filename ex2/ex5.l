%{
int COMMENT=0, fun=0,kw=0;
%}
%option noyywrap
identifier [a-zA-Z][a-zA-Z0-9]*
%%
#.* {printf("\nPD");}
int |
float |
char |
double |
while |
for |
struct |
typedef |
do |
if |
break |
continue |
void |
switch |
return |
else |
goto {printf("%s\tKW\n",yytext);}
printf |
scanf |
getch {fun=1;}{printf("%s\tFC\n",yytext);}
"/*" {COMMENT=1;}{printf("\n\t %s is a COMMENT",yytext);}
"*/" {COMMENT=0;}{printf("\n\t %s is a COMMENT",yytext);}
{identifier}\( {fun=1;} {if(!COMMENT)printf("%s\b\tFC\n",yytext);}
\{  {if(!COMMENT)printf("%s\tSP\n",yytext);}
\}  {if(!COMMENT)printf("%s\tSP\n",yytext);}
\(  {if(!COMMENT)printf("%s\tSP\n",yytext);}
\)  {if(!COMMENT)printf("%s\tSP\n",yytext);}
\;  {if(!COMMENT)printf("%s\tSP\n",yytext);}
\,  {if(!COMMENT)printf("");}
  
{identifier}(\[[0-9]*\])? {if(!COMMENT) printf("%s\tID\n",yytext);}
\"(([^\"]|\\\")*[^\\])?\" {if(!COMMENT)printf("%s\tSTR\n",yytext);}
[0-9]+ {if(!COMMENT) printf("%s\tNUM\n",yytext);}
= {if(!COMMENT)printf("%s\tASSIGN\n",yytext);}
[+] | 
[-] |
[*] |
[/] {if(!COMMENT)printf("%s\tOP\n",yytext);}
\<= |
\>= |
\< |
== |
\> {if(!COMMENT) printf("%s\tRELOP\n",yytext);}
%%
int main(int argc, char **argv)
{
FILE *file;
file=fopen(argv[1],"r");
if(!file)
{
printf("could not open the file");
exit(0);
}
yyin=file;
yylex();
printf("\n");
return(0);
}
