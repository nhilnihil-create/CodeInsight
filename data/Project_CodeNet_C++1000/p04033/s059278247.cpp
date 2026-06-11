#include<cstdio>
int a,b;
int main()
{
	scanf("%d%d",&a,&b);
	if(a>0)return printf("Positive"),0;
	if(a==0)return printf("Zero"),0;
	if(b>0)return printf("Zero"),0;
	if(b==0)return printf("Zero"),0;
	if((b-a+1)&1)return printf("Negative"),0;
	return printf("Positive"),0;
}