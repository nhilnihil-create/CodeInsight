#include <stdio.h>
int asiap(int x){
	if(x < 0){
		x *= -1;
	}
	return x;
}
int main(){
	
	int a,b,x;
	scanf("%d %d %d" , &x, &a, &b);
	if(asiap (x-a) > asiap (x-b)){
		printf("B");
	} 
	else{
		printf("A");
	}
	return 0;
}