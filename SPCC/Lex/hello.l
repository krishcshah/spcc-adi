%{

#include <string.h> 
#include <stdio.h>
#include <conio.h>

%}

%%
[^\n]+ {
	printf("Hello, %s", yytext);
}

%%

int yywrap(){}

int main() {
	yylex();
	printf("Enter your name:\n");
	return 0;
}
