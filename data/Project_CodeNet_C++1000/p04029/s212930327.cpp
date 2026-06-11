#include<stdio.h>
int main()
{
int C;
scanf("%d", &C);
int i;
int sum=0;
for(int i=1;i<=C;i++)
{
	sum = sum + i;
}
printf("%d", sum);
return 0;
}
