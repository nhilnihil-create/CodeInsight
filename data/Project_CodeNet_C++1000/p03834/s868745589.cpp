#include <stdio.h>
#include <string.h>

int main() {
	char n[255];
	scanf("%[^\n]", &n);
	
	int len = strlen(n);
	
	for(int i = 0; i < len; i++){
		if(n[i] == ','){
			printf(" ");
		}
		else {
			printf("%c", n[i]);
		}
	}
	printf("\n");
	return 0;
}