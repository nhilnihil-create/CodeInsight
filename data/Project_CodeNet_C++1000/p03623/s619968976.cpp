#include <stdio.h>

int main(){
	int x, a, b;
	scanf("%d %d %d", &x, &a, &b);
	int A = x - a;
	int	B = x - b;
	if (A < 0) A *= -1;
	if (B < 0) B *= -1;
	if (A < B){
		printf("A");
	}
	else {
		printf("B");
	}
	return 0;	
}