#include<stdio.h>
int a,b,c; 
int main()
{
	scanf("%d%d%d",&a,&b,&c);
	printf("%d\n",a==b&&a==c&&b==c?1:(a==b||a==c||b==c?2:3));
	return 0;
}