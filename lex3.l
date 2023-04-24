%{

// ctrl D for linux, ctrl Z for windows for end of Op

#include <string.h> 
#include <conio.h>
#include <stdio.h>

int lines = 0;
int words = 0;
int characters = 0;

%}

%%
\n      { lines++; }         
[a-zA-Z]+   { words++; characters += strlen(yytext); } 
.       { characters++; }   
%%

int yywrap() {}

int main() {
    yylex();
    printf("Lines: %d\n", lines);
    printf("Words: %d\n", words);
    printf("Characters: %d\n", characters);
    return 0;
}
