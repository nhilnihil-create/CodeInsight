#include<stdio.h>
int main(){
	int x;
	int A;
	int B;
	int result1;
	int result2;
	scanf("%d %d %d", &x, &A, &B);
	if(x < A){
		result1 = A - x;
	}else{
		result1 = x - A;
	}
	if(x < B){
		result2 = B - x;
	}else{
		result2 = x - B;
	}


	if(result1 < result2){
		printf("A");
	}else{
		printf("B");
	}
}