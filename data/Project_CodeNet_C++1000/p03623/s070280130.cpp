#include <stdio.h>

int main () {
	int point,a,b, distance1, distance2;
	scanf("%d %d %d", &point, &a, &b);
	
	distance1 = point - a;
	distance2 = point - b;
	if (distance1 < 0) {
		distance1 *= -1;
	} 
	if (distance2 < 0) {
		distance2 *= -1;
	}	 
	if (distance1 < distance2) {
		printf("A\n");
	} else {
		printf("B\n");
	}
	return 0;
}