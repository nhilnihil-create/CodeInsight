#include <stdio.h>

int main() {
	int x, a, b, i, j;
	scanf("%d %d %d", &x, &a, &b);
	i = x-a;
	j = x-b;
	if (i<0) {
		i *= -1;
	} 
	if (j<0) {
		j *= -1;
	}
	
	if (i>j) {
		printf("B");
		return 0;
	} else {
		printf("A");
	}
	return 0;
}