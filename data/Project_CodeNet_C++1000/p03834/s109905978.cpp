#include <stdio.h>

int main() {
	char str[21];
	
	scanf("%s", &str);
	
	for (int i = 0; i < 19; i++) {
		if (i != 5 && i != 13) {
			printf("%c", str[i]);
		}
		else if (i == 5 || i == 13) {
			printf(" ");
		}
	}
	
	return 0;
}