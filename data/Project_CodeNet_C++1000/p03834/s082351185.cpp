#include <stdio.h>
int main() {
	
	char str[19];
	scanf("%[^\n]", str);
	
	for (int i=0; str[i] != '\0'; i++){
		if (str[i] >= 'a' && str[i] <= 'z'){
			printf("%c",  str[i]);
		}
		else printf(" ");
	}
	
	return 0;
}