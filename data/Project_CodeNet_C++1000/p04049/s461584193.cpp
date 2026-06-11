#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define llong long long
using namespace std;

const int N = 4000;
struct Edge
{
	int v,nxt;
} e[(N<<1)+2];
int fe[N+3];
int fa[N+3];
int dep[N+3];
int n,m,en;

void addedge(int u,int v)
{
	en++; e[en].v = v;
	e[en].nxt = fe[u]; fe[u] = en;
}

int dfs(int u)
{
	if(dep[u]>m) return 0;
	int ret = (u<=n);
	for(int i=fe[u]; i; i=e[i].nxt)
	{
		if(e[i].v==fa[u]) continue;
		fa[e[i].v] = u;
		dep[e[i].v] = dep[u]+1;
		ret += dfs(e[i].v);
	}
	return ret;
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1; i<n; i++)
	{
		int x,y; scanf("%d%d",&x,&y);
		addedge(x,i+n); addedge(i+n,x);
		addedge(y,i+n); addedge(i+n,y);
	}
	int ans = 0;
	for(int i=1; i<=n+n-1; i++)
	{
		fa[i] = 0; dep[i] = 0;
		int tmp = dfs(i);
		ans = max(ans,tmp);
	}
	ans = n-ans;
	printf("%d\n",ans);
	return 0;
}