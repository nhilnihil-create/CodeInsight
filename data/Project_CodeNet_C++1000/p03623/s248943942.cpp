#include<stdio.h>

int main(){
	int n, a, b;
	scanf("%d %d %d", &n, &a, &b);
	int tota = n-a;
	if(tota<0){
		tota*=-1;
	}
	int totb = n-b;
	if(totb<0){
		totb*=-1;
	}
	if(tota<totb){
		printf("A\n");
	}
	else if(totb<tota){
		printf("B\n");
	}
	return 0;
}