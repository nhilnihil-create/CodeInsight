#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int s[10];
bool check(int n)
{
	while(n!=0)
	{
		if(s[n%10]==1) return false;
		n/=10;
	}
	return true;
}
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++)
	{
		int x;
		scanf("%d",&x);
		s[x]=1;
	}
	while(!check(n))
	{
		n++;
	}
	printf("%d\n",n);
}