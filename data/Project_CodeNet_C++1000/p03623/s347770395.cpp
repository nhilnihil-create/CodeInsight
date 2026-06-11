#include <stdio.h>

int main (){
	int x,a,b,bedaA=0,bedaB=0;
	scanf("%d %d %d", &x, &a, &b);
	 if (x>=a && x>=b){
	 	bedaA=x-a;
	 	bedaB=x-b;
	 }
	 else if(x>=a && x<=b){
	 	bedaA=x-a;
	 	bedaB=b-x;
	 }
	 else if(x<=a && x>=b){
	 	bedaA=a-x;
	 	bedaB=x-b;
	 }
	 else if(x<=a && x<=b){
	 	bedaA=a-x;
	 	bedaB=b-x;
	 }
	if(bedaA>bedaB){
		printf("B");
	}
	else{
		printf("A");
	}
	
	
	return 0;
}