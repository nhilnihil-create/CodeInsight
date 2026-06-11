#include<bits/stdc++.h>
using namespace std;
int n,a[100];
int main()
{
	cin>>n;
	int maxn=-998244353,minn=998244353;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		maxn=max(maxn,a[i]);
		minn=min(minn,a[i]);
	}
	long long g1=998244353,g2;
	int i;
	for(i=minn;i<=maxn;i++)
	{
		g2=0;
		for(int j=0;j<n;j++)
		{
			g2+=(a[j]-i)*(a[j]-i);
		}
		g1=min(g1,g2);
	}
	cout<<g1;
}