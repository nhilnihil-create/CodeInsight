#include <bits/stdc++.h>
using namespace std;

#define MAXN 300010

vector<int> edge[MAXN];
int fa[MAXN],color[MAXN],no,c2,el,visit[MAXN],n,m;

int findfa(int x)
{
	return fa[x]==x?x:fa[x]=findfa(fa[x]);
}

bool dfs(int u)
{
	for(auto v:edge[u])
	{
		if(color[v]==color[u])return false;
		if(color[v])continue;
		color[v]=3-color[u];
		if(!dfs(v))return false;
	}
	return true;
}

void cover(int u)
{
	visit[u]=true;
	for(auto v:edge[u])
	{
		if(visit[v])continue;
		cover(v);
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)fa[i]=i;
	for(int i=1;i<=m;++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		edge[u].push_back(v);
		edge[v].push_back(u);
		fa[findfa(u)]=findfa(v);
	}
	for(int i=1;i<=n;++i)
	{
		if(visit[i])continue;
		if(edge[i].empty())++no;
		else
		{
			color[i]=1;
			if(dfs(i))++c2;else ++el;
			cover(i);
		}
	}
	printf("%lld\n",(long long)no*no+(long long)no*(n-no)*2+(long long)el*c2*2+(long long)el*el+(long long)c2*c2*2);
}