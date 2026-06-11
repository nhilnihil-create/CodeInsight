#include <cstdio>

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	if (a + b >= 24)
	{
		printf("%d", a+b-24);
	}
	else 
	{
		printf("%d", a+b);
	}
	
}
