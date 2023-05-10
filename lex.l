Simple addition: %{ #include<stdio.h> int a,b,c;
%}
%%
"a" printf("enter the value of a:"); scanf("%d",&a); "b" printf("enter the value of b:"); scanf("%d",&b); "c" printf("the addition of %d,%d is %d:",a,b,c=a+b);
%%
int main()
{
yylex();
return 0;
}
int yywrap()
{
return 0;
}
Counting Vowels
%{
#include<stdio.h>
int vow=0,num=0,let=0; %}
%%
    
[aeiouAEIOU] vow++;
[0-9] num++;
[A-Za-z] let++;
";" printf("\nVOWELS=%d,LETTERS=%d,DIGITS=%d",vow,let,num); %%
int main() {
yylex(); return 0; }
int yywrap() {
return 0;
}
Counting tokens:
%{
#include<stdio.h>
#include<string.h>
char str[20];
int opc=0,dc=0,lc=0,varc=0,idc=0,key=0;
%}
ke (if|else|for|while|break|switch|do|default)
digit [0-9]
op [%|*|+|-|=]
id [_a-zA-Z][_a-zA-Z0-9]*
%%
{digit} dc++;
{op} opc++;
{ke} key++;
{id} idc++;
"\n" printf("digit %d\noperator%d,\nidentifier%d,keyword=%d",dc,opc,idc,key); %%
int main()
{
yylex();
return 0;
}
int yywrap()
{
return 0;
}