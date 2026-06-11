#include <bits/stdc++.h>
#define il inline
#define int long long
const int N=1e5+5;

int n,a[N],du[N];
int to[N+N],nx[N+N],hd[N],sze;

il void add(int u,int v){to[++sze]=v,nx[sze]=hd[u],hd[u]=sze,du[v]++;}

il bool dfs(int u,int F)
{
	int i,v,x=0,y=0,o=0;
	for (i=hd[u]; i; i=nx[i]) if ((v=to[i])!=F)
	{
		if (!dfs(v,u)) return 0;
		o=1,x+=a[v],y=std::max(y,a[v]);
	}
	if (!o) return 1;
	if (a[u]>x||a[u]<x-a[u]||a[u]<y) return 0;
	return a[u]-=x-a[u],1;
}

signed main()
{
	scanf("%lld",&n); int i,u,v;
	for (i=1; i<=n; i++) scanf("%lld",a+i);
	for (i=1; i<n; i++) scanf("%lld%lld",&u,&v),add(u,v),add(v,u);
	if (n==2) return puts(a[1]==a[2]?"YES":"NO"),0;
	
	for (i=1; i<=n; i++) if (du[i]==1) return puts(dfs(i,0)?"YES":"NO"),0;
	
	return 0;
}