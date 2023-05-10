STEPS TO EXECUTE:

1. yacc -d <filename>.yacc //yacc program compilation

2. ls //check files
	y.tab.c, y.tab.h

3. lex <filename>.lex //lex program compilation
	
4. ls //check files
	lex.yy.c

5. cc y.tab.c lex.yy.c //compilation of C program

6. ls //check files
	y.tab.o, lex.yy.o, a.out

7. ./a.out //show output


##########################################################################################################################################
//save file as type_checking.lex
LEX:

%{ 
#include<stdio.h> 
#include"y.tab.h" 
void yyerror(char *); 
int yylval; 
int yylineno; 
%} 
num [0-9] 
intg {num}{num}* 
floa {num}{num}*.({num}{1,2}) 
doub {num}{num}*.({num}{3,8}) 
%% 
{intg} { return INTEGER; } 
{floa} { return FLOAT; } 
{doub} { return DOUBLE; } 
[+=\n] return *yytext; 
[)( \t] {;} 
%% 
 int yywrap() 
{ 
return 1; 
} 


##########################################################################################################################################
//save file as type_checking.yacc
YACC:

%{
#include <stdio.h>
#include <stdlib.h>

int yylex();
void yyerror(char *);
int current_type;

%}

%token INT FLOAT DOUBLE

%%

program: type ID ';' { printf("Variable %s declared as %s.\n", $2, $1); }
        | program type ID ';' { printf("Variable %s declared as %s.\n", $3, $2); }
        ;

type: INT { current_type = INT; }
    | FLOAT { current_type = FLOAT; }
    | DOUBLE { current_type = DOUBLE; }
    ;

%%

int main() {
    yyparse();
    return 0;
}

void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
}

