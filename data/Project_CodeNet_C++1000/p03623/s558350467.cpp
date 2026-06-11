#include <stdio.h>

int main() {
	int a, b, c;
	
	scanf("%d %d %d", &a, &b, &c);

	int d = a - b;
	int e = a - c;
	
	if(d < 0) {		
		d *= -1;
	}
	
	if(e < 0) {
		e *= -1;	
	}

	
	if(d < e) {
		printf("A\n");
	}
	else if (e < d) {
		printf("B\n");
	}
	return 0;
}