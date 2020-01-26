#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
struct symboltable{
	char name[10];
	char type[10];
	int size;
	int address;
	char value[10];
}table[10];



int main() {
	char s[1024],buf[1024];
	int i=0;
	FILE *f = fopen("./input.txt","r");
	while(!feof(f)) {
		fgets(buf,100,f);
		strcpy(s,buf);
		//printf("%s\n", s);
		if(strstr(s,"#")) {
			printf("PD");
		}
		else if(strstr(s,"{") || strstr(s,"}")) {
			printf("SP");	
		}
		else if(strstr(s,"(") && strstr(s,")")) {
			printf("FC");
		}
		else{
		char *t = strtok(s," ");
		if(!strcmp(t,"int")||!strcmp(t,"float")||!strcmp(t,"double")||!strcmp(t,"char")) {
			printf("KW ");
			strcpy(table[i].type,t);
			if(!strcmp(table[i].type,"int")) {
				table[i].size=2;
			}
			if(!strcmp(table[i].type,"float")) {
				table[i].size=4;
			}
			if(!strcmp(table[i].type,"double")) {
				table[i].size=8;
			}
			if(!strcmp(table[i].type,"char")) {
				table[i].size=1;
			}
			t = strtok(NULL," ");
			char *tt = strtok(t,"=");
			strcpy(table[i].name,tt);
			printf("ID ");
			tt = strtok(NULL,"=");
			if(i==0) {
				table[i].address=1000;
			}
			else {
				table[i].address = table[i-1].address + table[i-1].size;
			}
			char *ttt = strtok(tt,";");
			strcpy(table[i].value,ttt);
			if(ttt!=NULL) {
				printf("NUM");
			}
		}
		i++;

			}

		printf(" <-> %s\n",buf);
		
	}
	int j;
	printf("Symbol table\n");
	printf("Name\tType\tSize\tAddress\tValue\n");
	for(j=0;j<i;j++) {
		printf("%s\t%d\t%s\t%d\t%s\n", table[j].name,table[j].size,table[j].type,table[j].address,table[j].value);
	}
	fclose(f);
	return 0;
}

