#include <stdio.h>

int main(){
	
	int x, a, b;
	scanf("%d %d %d", &x, &a, &b);
	
	int r1, r2;
	
	r1 = x>=a? x-a : a-x;
	r2 = x>=b? x-b : b-x;
	
	if(r1<r2){
		printf("A");
	}else {
		printf("B");
	}
	
	
	
	
	return 0;
}