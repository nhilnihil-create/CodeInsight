#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
int n,K,cnt,ans;
int fir[101010],nxt[101010],to[101010],dep[101010],fa[101010];
priority_queue<pair<int,int> > q;
bool d[101010];
void add(int x,int y)
{
	nxt[++cnt]=fir[x];fir[x]=cnt;
	to[cnt]=y;
}
void dfs(int x)
{
	for(int i=fir[x];i;i=nxt[i])
	{
		dep[to[i]]=dep[x]+1;
		q.push(make_pair(dep[to[i]],to[i]));
		dfs(to[i]);
	}
}
void update(int x)
{
	d[x]=1;
	for(int i=fir[x];i;i=nxt[i])
	if(!d[to[i]])
		update(to[i]);
}
int main()
{
	scanf("%d%d",&n,&K);
	for(int i=1;i<=n;i++)
		scanf("%d",&fa[i]);
	if(fa[1]!=1) ans++;
	for(int i=2;i<=n;i++)
	add(fa[i],i);
	dfs(1);
	while(!q.empty())
	{
		int x=q.top().second;q.pop();
		if(d[x]) continue;
		if(dep[x]<=K) break;
		int md=dep[x]-K+1;
		ans++;
		while(dep[x]>md) x=fa[x];
		update(x);
	}
	printf("%d\n",ans);
	return 0;
}