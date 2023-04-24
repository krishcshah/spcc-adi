%{
	
%}

%%
[\n] {
	printf("Hello world!");
	return 0;
}
%%

int yywrap(){}

int main() {
	yylex();
	return 0;
}