#include <stdio.h>

int main (){
	int x,a,b,x1,x2;
	
	scanf ("%d %d %d", &x,&a,&b);
	
	x>a ? x1=x-a : x1=a-x;
	x>b ? x2=x-b : x2=b-x;
	
	if (x1<x2){
		printf ("A");
	}
	else {
		printf ("B");
	}
	
	return 0;
}