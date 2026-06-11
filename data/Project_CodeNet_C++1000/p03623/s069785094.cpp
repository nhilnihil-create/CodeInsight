#include<stdio.h>

int main(){
	int x,a,b;
	int xa;
	int xb;
	scanf("%d %d %d", &x,&a,&b);
	if(x>a){
		xa= x-a;
	}else{
		xa= (x-a)*-1;
	}
	 if(x>b){
		xb=x-b;
	} else{
		xb=(x-b)*-1;
	}
	 if(xa<xb){
	 	printf("A");
	 }else{
	 	printf("B");
	 }
	
	
	
	return 0;
}