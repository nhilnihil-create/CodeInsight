#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
vector<int>g[2005];
int n,m,ml,sum;
inline void dfs(int x,int fa,int d)
{
	if(d>m/2)
		sum++;
	for(int i=0;i<g[x].size();i++)
		if(g[x][i]!=fa)
			dfs(g[x][i],x,d+1);
}
inline void dfs1(int x,int fa,int d)
{
	if(d>m/2)
		sum++;
	for(int i=0;i<g[x].size();i++)
		if(g[x][i]!=fa)
			dfs(g[x][i],x,d+1);
	for(int i=0;i<g[fa].size();i++)
		if(g[fa][i]!=x)
			dfs(g[fa][i],fa,d+1);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	int ans=0x3f3f3f3f;
	if(m%2==0)
	{
		for(int i=1;i<=n;i++)
		{
			sum=0;
			dfs(i,0,0);
			ans=min(sum,ans);
		}
		printf("%d\n",ans);
	}
	else
	{
		for(int i=1;i<=n;i++)
			for(int x=0;x<g[i].size();x++)
			{
				sum=0;
				dfs1(i,g[i][x],0);
				ans=min(sum,ans);
			}
		printf("%d\n",ans);
	}
}////