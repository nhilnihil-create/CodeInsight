#include <stdio.h>
int main() {
	int x,a,b;
	scanf("%d %d %d",&x,&a,&b);
	
	int ax;
	
	if ( x > a )
	{
		ax = x - a;
	}
	else if ( a > x )
	{
		ax = a - x;
	}
	
	int bx;
	
	if (x > b)
	{
		bx = x - b;
	}
	else if (b > x)
	{
		bx = b - x;
	}
	
	if (ax < bx)
	{
		printf("A\n");
	}
	else if (ax > bx)
	{
		printf("B\n");
	}
	return 0;
}