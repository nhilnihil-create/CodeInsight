#include <stdio.h>

int main(){
	int x, a, b, d1, d2;
	
	scanf("%d %d %d", &x, &a, &b);

	if(a>x)
		d1 = a-x;
	else 
		d1 = x-a;
	
	if(b>x)
		d2 = b-x;
	else
	 	d2 = x-b;
	 	
	if(d1>d2)
		printf("B");
	else
		printf("A");
	
	return 0;
}
