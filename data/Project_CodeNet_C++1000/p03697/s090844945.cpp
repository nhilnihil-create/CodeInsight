#include <cstdio>

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	if (a + b < 10)
	{
		printf("%d", a+b);
	}
	else if (a + b >= 10)
	{
		printf("error");
	}
}
