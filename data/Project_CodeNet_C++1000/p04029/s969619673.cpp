#include <stdio.h>

int main() {
	int child, candy = 0;
	scanf("%d", &child);
	
	for(int i = 0; i < child; i++) {
		for(int j = 0; j < i; j++) {
			candy += 1;			
		}
		candy++;
	}
	printf("%d", candy);
	
	return 0;
}