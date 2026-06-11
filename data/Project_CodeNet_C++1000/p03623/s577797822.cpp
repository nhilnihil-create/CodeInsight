#include<stdio.h>
#include<string.h>

int main(){
    
	int x, a, b, A, B;
	
	scanf("%d %d %d", &x, &a, &b);
	
	if(x>a){
		A = x - a;
	}else{
		A = a - x;
	}	

	if(x>b){
		B = x - b;
	}else{
		B = b - x;
	}
	
	if(A<B){
		printf("A");
	}else{
		printf("B");
	}
}
	