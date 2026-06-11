#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<queue>
#include<bitset>
#include<map>
using namespace std;
template<typename __T>
inline void read(__T &x)
{
    x=0;
    int f=1;char c=getchar();
    while(!isdigit(c)){if(c=='-')	f=-1;c=getchar();}
    while(isdigit(c))	{x=x*10+c-'0';c=getchar();}
    x*=f;
}
bool vis[305][305];
int dis[305][305];
int n;
int main()
{
	read(n);
	memset(vis,1,sizeof(vis));
	for(int i=1;i<=n;i++)
		vis[i][i]=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			read(dis[i][j]);
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			{
				if(i==k || j==k)	continue;
				if(dis[i][j]>dis[i][k]+dis[k][j])
				{
					printf("-1\n");
					return 0;
				}
				if(dis[i][j]==dis[i][k]+dis[k][j])
					vis[i][j]=0;
			}
	long long ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(vis[i][j])	ans+=dis[i][j];
	cout<<ans/2<<endl;
	return 0;
}
