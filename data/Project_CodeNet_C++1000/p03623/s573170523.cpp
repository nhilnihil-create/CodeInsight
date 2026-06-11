#include <stdio.h>
int main() {
	int x, a, b;
	scanf("%d %d %d",&x,&a,&b);
	
	int ax = 0;
	if (x > a)
	{
		ax = x - a;
	}
	else
	{
		ax = a - x;
	}
	
	int bx = 0;
	if (x > b)
	{
		bx = x - b;
	}
	else
	{
		bx = b - x;
	}
	
	if (ax > bx)
	{
		printf("B\n");
	}
	else 
	{
		printf("A\n");
	}
	return 0;
}