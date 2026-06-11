#include <stdio.h>

int main(){
	int x, a, b;
	scanf("%d %d %d", &x, &a, &b);
	int a1 = x- a;
	int b1 = x -b ;
	if(a1 < 0){
		a1 *= -1;
	}
	if(b1 < 0){
		b1 *= -1;
	}
	if(a1 < b1){
		printf("A");
	}else{
		printf("B");
	}
	
	return 0;
}