#include<cstdio>
#include<string>
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	if((a+b)%3==0||a%3==0||b%3==0)
	{
		printf("Possible\n");
	}
	else
	{
		printf("Impossible\n");
	}
	return 0;
}