#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#define maxn 305
using namespace std;
typedef long long ll;
int n;
int dis[maxn][maxn];
int can[maxn][maxn];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&dis[i][j]);

	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			if(i!=j && j!=k && k!=i)
			{
				if(dis[i][j]>dis[i][k]+dis[k][j])
					return printf("-1\n"),0;
				else if(dis[i][j]==dis[i][k]+dis[k][j])
				can[i][j]=1;
			}
		}
	}
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		if(!can[i][j])
			ans+=dis[i][j];
	}
	printf("%lld\n",ans);
}
