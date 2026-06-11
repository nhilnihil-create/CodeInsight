#include <stdio.h>
#include <string.h>

int main () {
	char ch[105];
	scanf("%[^\n]", ch);
	
	for(int i = 0; i < 19; i++){
		if (ch[i] == ',') {
			printf(" ");
		}
		else {
			printf("%c", ch[i]);
		}
	}
	
	return 0;
}