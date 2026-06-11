#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=100005;
int n,m,i,j,k,head[N],adj[N*2],nxt[N*2],p[N],cnt;
bool v[N];
void dfs(int x)
{
	v[x]=true;
	for(int y=head[x];y;y=nxt[y])
		if(!v[adj[y]])
		{
			dfs(adj[y]);
			break;
		}
	p[++cnt]=x;
}
void Dfs(int x)
{
	if(x!=1)
		p[++cnt]=x;
	v[x]=true;
	for(int y=head[x];y;y=nxt[y])
		if(!v[adj[y]])
		{
			Dfs(adj[y]);
			break;
		}
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
	dfs(1);
	Dfs(1);
	printf("%d\n",cnt);
	for(i=1;i<=cnt;++i)
		printf("%d ",p[i]);
	return 0;
}
