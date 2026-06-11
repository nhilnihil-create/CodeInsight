#include <stdio.h>
#include <math.h>

int main() {
	int x,A,B;
	scanf("%d %d %d", &x, &A, &B);
	int da = abs(A-x);
	int db= abs(B-x);
	
	
	if(da < db){
		printf("A");
	}
	else{
		printf("B");
	}
	
	return 0;
}
	