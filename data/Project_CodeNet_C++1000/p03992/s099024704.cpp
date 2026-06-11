#include<cstdio>
#include<string.h>
char s[99];
int main(){
	scanf("%s",&s);
	for(int i=0;i<strlen(s);i++){
		putchar(s[i]);
		if(i==3)putchar(' ');
	}
	puts("");
}