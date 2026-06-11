#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
int n;
int a[105],minn,minnum,maxx,maxnum,num[105];
int main()
{
	scanf("%d",&n);
	minn=1e9,maxx=0;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),minn=min(minn,a[i]),maxx=max(maxx,a[i]);
	for(int i=1;i<=n;i++) num[a[i]]++;
	if(num[minn]>2)
	{
		puts("Impossible");
		return 0;
	}
	if(num[minn]==1)
	{
		if(minn*2!=maxx)
		{
			puts("Impossible");
			return 0;
		}
	}
	else
	{
		if(minn*2-1!=maxx)
		{
			puts("Impossible");
			return 0;
		}
	}
	for(int i=minn+1;i<=maxx;i++)
	{
		if(num[i]<2)
		{
			puts("Impossible");
			return 0;
		}
	}
	puts("Possible");
	return 0;
}