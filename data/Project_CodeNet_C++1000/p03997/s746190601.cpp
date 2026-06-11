#include<iostream>
#include<cmath>
#include<math.h>
#include<algorithm>
#include<cstring>
#include<string>
#include<cstdio>
using namespace std;
int P(int a)
{
	int flag=1;
	for (int i=2;i<=sqrt(a);i++)
	{
		if (a%i==0)
		{
			flag=0;
		}
	}
	if (a<2)
	{
		return 0;
	}
	if (flag==1||a==2)
	{
		return 1;
	}
	if (flag==0)
	{
		return 0;
	}
	return 0;
}
int main()
{
	double a,b,c;
	cin>>a>>b>>c;
	cout<<(a+b)*c/2;
	return 0;
}
