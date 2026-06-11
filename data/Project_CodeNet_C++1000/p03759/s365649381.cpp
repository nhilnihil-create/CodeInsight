#include<stdio.h>
int main()
{
	int a,b,c;
	while(~scanf("%d%d%d",&a,&b,&c))
	{
		if(b-a==c-b)
		printf("YES\n");
		else
		printf("NO\n");
	}
}