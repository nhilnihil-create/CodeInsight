#include <stdio.h>
 
int main (){
	char s[255];
	scanf("%[^\n]", s);
	for (int i= 0; s[i] != '\0'; i++){
		if (s[i] >='a' && s[i]<= 'z'){
			printf("%c", s[i]);
		}else{
			printf(" ");
		}
	}
	puts("");
 
	return 0;
}