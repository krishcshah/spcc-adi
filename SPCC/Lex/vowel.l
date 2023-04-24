%{
	void display(int flag);
%}

%%

[a|e|i|o|u]+ {
	int flag = 1;
	display(flag);
	return 0;
}

.+ {
	int flag = 0;
	display(flag);
	return 0;
}

%%

void display(int flag) {
	if(flag == 0) {
		printf("NOT a vowel!");
	}
	else {
		printf("Vowel!");
	}
}

int yywrap() {}

int main() {
	printf("Enter a word to check if its a vowel or not:\n");
	yylex();
}
