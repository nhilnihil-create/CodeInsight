#include <stdio.h>

int main(){	
	char str[25];
	scanf("%s", str);
	
	for(int i=0; str[i]!='\0'; i++){
		if(str[i]==','){
			printf(" ");
		} else {
		printf("%c", str[i]);
		}
	}
	
	puts(" ");
	return 0;
}