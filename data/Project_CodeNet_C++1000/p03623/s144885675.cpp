#include <stdio.h>

int main() {
	
	int x, A, B, sum1, sum2;
	scanf("%d %d %d", &x, &A, &B);
	sum1 = x - A;
	sum2 = x - B;
	
	if(sum1 < 0){
		sum1 *= -1;
	}
	else{
		sum1 *= 1;
	}
	
	if(sum2 < 0){
		sum2 *= -1;
	}
	else{
		sum2 *= 1;
	}
	
	if(sum1 > sum2){
		printf("B");	
	}
	else{
		printf("A");
	}
	
	return 0;
}