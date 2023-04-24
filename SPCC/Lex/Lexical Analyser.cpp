%{

#include <stdio.h> 
#include <string.h>
char *keywords[] = { "if", "else", "for", "while", "do", "int", "float", "char", "return" }; 

int isKeyword(char *word) {
    int n = sizeof(keywords) / sizeof(keywords[0]);
    for (int i=0; i<n; i++) {
        if (strcmp(keywords[i], word) == 0) return 1; 
    }
    return 0;
} 

%}

%%
[a-zA-Z][a-zA-Z0-9]* {
    if (isKeyword(yytext)) {
        printf("KEYWORD: %s\n", yytext);
    }
    else {
        printf("IDENTIFIER: %s\n", yytext);
    }
}

[0-9]+ printf("CONSTANT: %s\n", yytext);

\+|\=|\-|\*|\/ printf("OPERATOR: %s\n", yytext);

\(|\)|\{|;|,|\} printf("SEPARATOR: %s\n", yytext);

\n 
return 0;
%%

int main() {
    yylex();
    return 0; 
} 
