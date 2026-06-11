#include<stdio.h>
int max(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	int x;
	x=max(max(a,b),c);
	if(a+b+c==2*x)
		printf("Yes\n");
	else
		printf("No\n");
}