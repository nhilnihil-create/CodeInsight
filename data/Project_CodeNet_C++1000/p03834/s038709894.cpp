#include <stdio.h>

int main(){
	char str[20];
	scanf("%s", &str);
	str[5] = ' ';
	str[13] = ' ';

	for (int i = 0; str[i] != '\0'; i++){
	printf("%c", str[i]);
	}
	return 0;
}