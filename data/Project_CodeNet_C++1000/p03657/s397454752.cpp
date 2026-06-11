#include <cstdio>

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	if ((a+b)%3 == 0)
	{
		printf("Possible");
	}
	else if (a%3 == 0)
	{
		printf("Possible");
	}
	else if (b%3 == 0)
	{
		printf("Possible");
	}
	else
	{
		printf("Impossible");
	}
}
