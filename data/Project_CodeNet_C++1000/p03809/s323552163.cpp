//Cleaning
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long lint;
int const N=1e5+10;
int n,a[N];
int cnt,h[N],deg[N];
struct edge{
	int u,v,nxt;
	edge(int u1=0,int v1=0)
	{
		u=u1,v=v1;
		nxt=h[u];
		h[u]=cnt;
	}
}ed[N<<1];
int root,fa[N],dpt[N];
struct rec{int dpt,id;} r[N];
bool cmpDpt(rec x,rec y) {return x.dpt>y.dpt;}
void dfs(int u)
{
	for(int i=h[u];i!=0;i=ed[i].nxt)
	{
		int v=ed[i].v;
		if(v==fa[u]) continue;
		fa[v]=u,dpt[v]=dpt[u]+1;
		dfs(v);
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	if(n==2)
	{
		if(a[1]!=a[2]) printf("NO");
		else printf("YES");
		return 0;
	}
	cnt=0; memset(h,0,sizeof h);
	for(int i=1;i<=n-1;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		ed[++cnt]=edge(u,v); deg[v]++;
		ed[++cnt]=edge(v,u); deg[u]++;
	}
	for(int i=1;i<=n;i++)
		if(deg[i]>1)
		{
			fa[i]=0,dpt[i]=1;
			dfs(root=i);
			break;
		}
	for(int i=1;i<=n;i++) r[i].dpt=dpt[i],r[i].id=i;
	sort(r+1,r+n+1,cmpDpt);
	for(int i=1;i<=n;i++)
	{
		int u=r[i].id;
		if(deg[u]==1) continue;
		int maxx=0; lint sum=0;
		for(int j=h[u];j!=0;j=ed[j].nxt)
		{
			int v=ed[j].v;
			if(fa[v]!=u) continue;
			maxx=max(maxx,a[v]); sum+=a[v];
		}
		lint in=min(sum/2,sum-maxx);
		if(a[u]>sum) {printf("NO"); return 0;}
		else
		{
			if(sum-a[u]>in) {printf("NO"); return 0;}
			else a[u]-=sum-a[u];
		}
	}
	if(a[root]==0) printf("YES");
	else printf("NO");
	return 0;
}