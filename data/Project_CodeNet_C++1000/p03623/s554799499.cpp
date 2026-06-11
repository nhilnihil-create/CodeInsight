#include<stdio.h>
int main(){
	int x;
	int a;
	int b;
	scanf("%d %d %d", &x ,&a, &b);
	int r1satu;
	int r2dua;
	
	r1satu= x>=a? x-a : a-x;
	r2dua= x>=b? x-b : b-x;
	
	if(r1satu<r2dua){
		printf("A");
	}else{
		printf("B");
	}
	return 0;
}