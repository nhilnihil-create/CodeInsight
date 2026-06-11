#include <cstdio>

int main()
{
	int a,b,c;
	scanf("%d %d %d", &a, &b, &c);
	if(a+b==c)
	{
		printf("Yes");
	}
	else if(a+c==b)
	{
		printf("Yes");
	}
	else if(b+c==a)
	{
		printf("Yes");
	}
	else
	{
		printf("No");
	}
}