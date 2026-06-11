#include <cstdio>

int main()
{
	int a;
	scanf("%d", &a);
	if ((a%10) == (a/100))
	{
		printf("Yes");
	}
	else 
	{
		printf("No");
	}
}
