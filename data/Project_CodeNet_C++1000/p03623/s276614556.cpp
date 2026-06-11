#include <stdio.h>

int main() {
	int pos, a, b, distA, distB;
	scanf("%d %d %d", &pos, &a, &b);
	
	distA = a - pos;
	distB = b - pos;
	if(distA < 0) {
		distA *= -1;
	} if(distB < 0) {
		distB *= -1;
	}
	
	if(distA < distB) {
		printf("A");
	} else {
		printf("B");
	}
	
	return 0;
}