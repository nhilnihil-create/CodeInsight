#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define mod 1000000007
using namespace std;

long long x,y;

int main()
{
	scanf("%lld%lld",&x,&y);
	if(abs(x-y)<=1)
	{
		puts("Brown");
	}
	else
	{
		puts("Alice");
	}
}