#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=100005;
int n,m,q,i,j,k,v[N],d[N],c[N],col[N],head[N],adj[N*2],nxt[N*2];
bool vis[N][15];
void dfs(int x,int d)
{
	if(!col[x])
		col[x]=c[i];
	vis[x][d]=true;
	if(d==0)
		return;
	for(int y=head[x];y;y=nxt[y])
		if(!vis[adj[y]][d-1])
			dfs(adj[y],d-1);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;++i)
	{
		scanf("%d%d",&j,&k);
		adj[i*2-1]=k;
		nxt[i*2-1]=head[j];
		head[j]=i*2-1;
		adj[i*2]=j;
		nxt[i*2]=head[k];
		head[k]=i*2;
	}
	scanf("%d",&q);
	for(i=1;i<=q;++i)
		scanf("%d%d%d",v+i,d+i,c+i);
	for(i=q;i>=1;--i)
	if(!vis[v[i]][d[i]])
		dfs(v[i],d[i]);
	for(i=1;i<=n;++i)
		printf("%d\n",col[i]);
	return 0;
}
