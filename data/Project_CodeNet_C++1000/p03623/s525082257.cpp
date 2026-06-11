#include <stdio.h>

int main(){
	int x, a, b;
	scanf("%d%d%d", &x, &a, &b);
	
	int lineA;
	
	if ( a < x){
		lineA = x -a;
     }
     	
	else if (a > x){
		lineA= a - x;
	}
	
	int lineB;
	
	if ( b < x){
		lineB = x - b;
     }
     	
	else if (b > x){
		lineB= b - x;
	}
	
	if (lineA < lineB){
		printf("A\n");
	}
	else if (lineB < lineA){
		printf("B\n");
	}
	return 0;
}