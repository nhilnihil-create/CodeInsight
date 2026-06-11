#include<stdio.h>
#include<string.h>
char x[105];
int main(){
	
	scanf("%s",x);
	for(int i=0;i<strlen(x);i++){
		if(x[i]==',')
			printf(" ");
		else
			printf("%c",x[i]);
	}
}