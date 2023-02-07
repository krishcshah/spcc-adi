%{
	
%}

%%
[\n] {
	printf("Hello world!");
	return 0;
}
%%

int main() {
	yylex();
}
