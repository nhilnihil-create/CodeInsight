#include <stdio.h>

int main ()
{
	int x, a, b;
	scanf("%d %d %d", &x, &a, &b);
	
	if(x>a && x>b)
	{
		if(x-a > x-b)
		{
			printf("B");
		}
		else
		{
			printf("A");
		}
	}
		
	else if(x>a && x<b)
	{
		if(x-a > b-x)
		{
			printf("B");
		}
		else
		{
			printf("A");
		}
	}
		
	else if(x<a && x>b)
	{
		if(a-x > x-b)
		{
			printf("B");
		}
		else
		{
			printf("A");
		}
	}
	
	else if(x<a && x<b)
	{
		if(a-x > b-x)
		{
			printf("B");
		}
		else
		{
			printf("A");
		}
	}
		
	return 0;
}