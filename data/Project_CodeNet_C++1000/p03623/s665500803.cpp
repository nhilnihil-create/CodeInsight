#include<stdio.h>

int main(){
	
	int x, a, b;
	scanf("%d %d %d", &x, &a, &b);
	int sum1 = x-a;
	int sum2 = x-b;
	if(sum1 < 0){
		sum1*= -1; 
	}if(sum2 < 0){
		sum2*= -1;
	}
	
	(sum1<sum2) ? printf("A") : printf("B");
	return 0;
}