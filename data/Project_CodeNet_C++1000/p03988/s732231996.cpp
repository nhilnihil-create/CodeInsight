#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
const int N=105;
int n;
int t[N];
int mx=0;
int main()
{
	scanf("%d",&n);
	for (int u=1;u<=n;u++)
	{
		int x;
		scanf("%d",&x);
		mx=max(mx,x);
		t[x]++;
	}
	if (t[mx]<2) 
	{
		printf("Impossible\n");
		return 0;
	}
	int x=(mx+1)/2;
	for (int u=1;u<x;u++) 
		if (t[u]!=0) 
		{
			printf("Impossible\n");
			return 0;
		}
	if (t[x]!=(mx&1)+1)
	{
		printf("Impossible\n");
		return 0;
	}
	for (int i=x;i<=mx;i++)
	{
		if (t[i]==0)
		{
			printf("Impossible\n");
			return 0;
		}
		t[i]--;
	}
	int now=mx/2;
	for (int i=now+1;i<=mx;i++)
		if (t[i]==0)
		{
			printf("Impossible\n");
			return 0;
		}
	printf("Possible\n");
	return 0;
}