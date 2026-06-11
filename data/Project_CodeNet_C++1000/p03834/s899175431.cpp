#include <stdio.h>

int main(){
	char s[19];
	scanf("%[^\n]",s);
	int lol;
	for(int i=0;i<19;i++){
		if(s[i]==','){
			printf(" ");
		}else {
			printf("%c",s[i]);
		}
	}
return 0;
}