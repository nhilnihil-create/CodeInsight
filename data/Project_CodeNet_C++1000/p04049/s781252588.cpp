#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int mod=1e9+7;
const int maxn=2010;
int n,k;
vector<int> g[maxn];
int dis[maxn][maxn];
void dfs(int rt,int u,int fa,int dep)
{
	dis[rt][u]=dep;
	int sz=(int)g[u].size();
	for(int i=0;i<sz;i++)
	{
		int v=g[u][i];
		if(v==fa) continue;
		dfs(rt,v,u,dep+1);
	}
}
pair<int,int> p[maxn];
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		g[a].push_back(b);
		g[b].push_back(a);
		p[i]=make_pair(a,b);
	}
	for(int i=1;i<=n;i++)
		dfs(i,i,-1,0);
	int minx=n;
	for(int i=1;i<=n;i++)
	{
		int cnt=0;
		for(int j=1;j<=n;j++)
			if(dis[j][i]*2>k) cnt++;
		minx=min(minx,cnt);
	}
	for(int i=1;i<=n-1;i++)
	{
		int cnt=0;
		for(int j=1;j<=n;j++)
			if(2*min(dis[j][p[i].first],dis[j][p[i].second])+1>k)
			cnt++;
		minx=min(minx,cnt);
	}
	printf("%d\n",minx);
	return 0;
}