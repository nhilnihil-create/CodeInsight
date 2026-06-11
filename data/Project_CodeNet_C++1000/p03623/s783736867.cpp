#include<stdio.h>
int main()
{
	int x,a,b;
	scanf("%d %d %d",&x,&a,&b);
	int sum1,sum2;
	sum1 = x-a;
	sum2 = x-b;
	sum1 < 0 ? sum1 *= -1 : sum1;
	sum2 < 0 ? sum2 *= -1 : sum2;
	sum1 < sum2 ? printf("A\n") : printf("B\n");
	return 0;
}