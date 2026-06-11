#include <stdio.h>

int main() {
	char str[19];
	scanf("%[^\n]", &str);
	for ( int a = 0; a < 19; a++){
		if(str[a] == ','){
			printf(" ");
		}
		else{
			printf("%c", str[a]);
		}
	}
	return 0;
}
