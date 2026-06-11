#include <stdio.h>

int main() {
	int Snuck, RstA, RstB, JrkA, JrkB;
	scanf("%d %d %d", &Snuck, &RstA, &RstB);
	
	JrkA = RstA - Snuck;
	JrkB = RstB - Snuck;
	if (JrkA < 0) {
		JrkA *= -1;
	}if (JrkB < 0) {
		JrkB *= -1;
	}
	if (JrkA < JrkB) {
		printf("A\n");
	} else {
		printf("B\n");
	}
	
	
	return 0;
}