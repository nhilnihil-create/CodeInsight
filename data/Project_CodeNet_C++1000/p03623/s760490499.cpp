#include<stdio.h>
#include<math.h>

int main()
{
	int x, a, b;
	scanf("%d %d %d", &x, &a, &b);
	
	int sa, sb;
	sa = abs(x - a);
	sb = abs(x - b);
	
	if (sa < sb)
	{
		printf("A\n");
	}
	
	else if (sa > sb)
	{
		printf("B\n");
	}
	
	return 0;
}