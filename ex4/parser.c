#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char input[100];
int i,error;

void E();

void F() {
	printf("        F()\n");
	if(isalpha(input[i])) {
		//printf("%c", input[i]);
		i++;
		//printf(" %d\n", i);
		while(isalpha(input[i])) {
			//printf("%c", input[i]);
			i++;
			//printf(" %d\n", i);
		}
	}
	else if(input[i]=='(') {
		//printf("%c", input[i]);
		i++;
		//printf(" %d\n", i);
		E();
		if(input[i]==')') {
			//printf("%c", input[i]);
			i++;
			//printf(" %d\n", i);
		}
		else
			error=1;
	}
	else 
		error=1;
}

void Tprime() {
	printf("        T\'()\n");
	if(input[i]=='*') {
		//printf("%c", input[i]);
		i++;
		//printf(" %d\n", i);
		F();
		Tprime();
	}
}

void T() {
	printf("    T()\n");
	F();
	Tprime();
}

void Eprime() {
	printf("    E\'()\n");
	if(input[i]=='+') {
		//printf("%c", input[i]);
		i++;
		//printf(" %d\n", i);
		T();
		Eprime();
	}
}

void E() {
	printf("E()\n");
	T();
	Eprime();
}

int main() {
	i=0;
	error=0;
	printf("Enter the string to be parsed: ");
	scanf("%s",input);
	E();
	//printf("i at end=%d\n",i);
	//printf("strlen=%ld\n",strlen(input));
	int l = strlen(input);
	//printf("error=%d\n", error);
	if(error==0 && l==i) 
		printf("Accepted\n");
	else
		printf("Rejected\n");
	
}