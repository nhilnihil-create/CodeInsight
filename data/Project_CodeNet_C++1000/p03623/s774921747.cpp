#include <stdio.h>

int main(){
	int x;
	int a;
	int b;
	int xa;
	int xb;
	scanf("%d %d %d", &x, &a, &b);
	xa=x-a;
	if(xa<0){
		xa*=-1;
	}
	xb=x-b;
	if(xb<0){
		xb*=-1;
	}
	if(xa>xb){
		printf("B");
	}else{
		printf("A");
	}

	
	return 0;
}