%{
    int lineCount = 0, charCount = 0;
%}

%%
. {charCount++;}
\n {lineCount++; charCount++;}
%%

int main() { 
    yylex();
    printf("No. of lines = %d, No. of chars = %d", lineCount, charCount);
}
