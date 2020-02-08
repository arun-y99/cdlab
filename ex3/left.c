#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct production {
	char *lhs,*rhs;
};

int main() {
	struct production exp[2],res[100];
	char s[1024];
	int k=0,i=0,j=0,x=0;
	while(1) {
		i=0;
		scanf("%s",s);
		if(!strcmp(s,"x"))
			break;
		char *t = strtok(s,"-");
		//printf("tbefore %s\n", t);
		
		char l[100]; strcpy(l,t);
		t = strtok(NULL,"-");
		//printf("tafter %s\n", t);
		char r[100];
		strcpy(r,t);
		//printf("rvalue %s\n", r);
		char *tt = strtok(r,"|");
		//printf("rafter %s\n", tt);
		while(tt!=NULL) {
			exp[i].lhs = (char*)malloc(10);
			exp[i].rhs = (char*)malloc(10);
			strcpy(exp[i].lhs,l);
			strcpy(exp[i].rhs,tt);
			tt = strtok(NULL,"|");
			//printf("lhs%s rhs%s\n", exp[i].lhs,exp[i].rhs);
			i++;
		}
		//printf("svalue 	%s\n",s);
		if(exp[0].lhs[0]==exp[0].rhs[0]) {
			res[k].lhs = (char*)malloc(10);
			res[k].rhs = (char*)malloc(10);
			strcpy(res[k].lhs,exp[0].lhs);
			strcpy(res[k].rhs,exp[1].rhs);
			strcat(res[k].rhs,exp[0].lhs);
			strcat(res[k].rhs,"\'");
			k++;
			res[k].lhs = (char*)malloc(10);
			res[k].rhs = (char*)malloc(10);
			strcpy(res[k].lhs,exp[0].lhs);
			strcat(res[k].lhs,"\'");
			int p;
			for(p=0;p<strlen(exp[0].rhs)-1;p++) {
				res[k].rhs[p]=exp[0].rhs[p+1];
			}
			strcat(res[k].rhs,exp[0].lhs);
			strcat(res[k].rhs,"\'|e");
			k++;
		}
		else {
			res[k].lhs = (char*)malloc(10);
			res[k].rhs = (char*)malloc(10);
			strcpy(res[k].lhs,exp[0].lhs);
			strcpy(res[k].rhs,exp[0].rhs);
			strcat(res[k].rhs,"|");
			strcat(res[k].rhs,exp[1].rhs);
			k++;
		}
	}
	printf("OUT\n");
	for(x=0;x<k;x++){
		printf("%s -> %s\n", res[x].lhs,res[x].rhs);

	}
	return 0;
}