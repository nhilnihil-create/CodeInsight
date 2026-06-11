#include <iostream>
#include <stdio.h>
#include <string.h>
#define MAX_N 305
#define int long long

using namespace std;

int n;
int dis[MAX_N][MAX_N];

signed main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%lld",&dis[i][j]);
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i!=j && j!=k && i!=k)
				{
					if(dis[i][j]>dis[i][k]+dis[k][j])
					{
						printf("-1\n");
						return 0;
					}
				}
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			bool flag=true;
			for(int k=1;k<=n;k++)
			{
				if(i!=j && j!=k && i!=k)
				{
					if(dis[i][j]==dis[i][k]+dis[k][j])
					{
						flag=false;
						break;
					}
				}
			}
			if(flag) ans+=dis[i][j];
		}
	}
	printf("%lld\n",ans);
}
