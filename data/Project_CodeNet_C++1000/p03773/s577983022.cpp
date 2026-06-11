#include <cstdio>
int main()
{	
	int a,b;
	scanf("%d %d", &a, &b);
	if(a+b<24)
	{
		printf("%d", a+b);
	}
	else if(a+b==24)
	{
		printf("0");
	}
	else if(a+b>24)
	{
		printf("%d",(a+b)-24);
	}
}
	
