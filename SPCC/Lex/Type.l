%{
	void display(int flag);
%}

%%
[a-zA-Z]+ {
	int flag = 1;
	display(flag);
	return 0;
}
[0-9]+ {
	int flag = 0;
	display(flag);
	return 0;
}
.+ {
	int flag = -1;
	display(flag);
	return 0;
}
%%

void display(int flag) {
	if(flag == 1) {	
		printf("Word");
	}
	else if(flag == 0) {
		printf("Number");
	}
	else {
		printf("Special charcter");
	}	
}

#include <stdio.h>
int main() {
	printf("Enter a word\n");
	yylex();
	return 0;
}
