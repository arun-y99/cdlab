%{   
#include "stdio.h"
#include "math.h"
int yylex(void);
void yyerror(char *); 
int sym[26]; 
int i, count=0;
%} 
 
%token INTEGER VARIABLE 
%left '+' '-' 
%left '*' '/'
%left '^'
%%
 program:   program statement '\n'  {  /*printf("%d\n",sym[count]);*/}
	    | ; 
statement:   expr   {  sym[++count]=$1;printf("Answer: %d\n",  $1); } 
	| VARIABLE '=' expr      { sym[++count]=$3;  count++; printf("%d\n",$3); }
              |;
 expr: INTEGER { $$ = $1; }
   | expr '+' expr           { $$ = $1 + $3; }  
   | expr '-' expr           { $$ = $1 - $3; }     
   | expr '*' expr           { $$ = $1 * $3; }       
   | expr '/' expr           { $$ = $1 / $3; }
   | expr '^' expr           { $$ = pow($1,$3); }     
   | '(' expr ')'            { $$ = $2; }        
   |;
 %% 

void yyerror(char *s)
{    
fprintf(stderr, "%s\n", s);    
 
}

int main()
{     
yyparse();   
  return 0;
}
