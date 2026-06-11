#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cassert>
#include<algorithm>
#define llong long long
using namespace std;

const int N = 1e5;
struct Edge
{
	int v,nxt;
} e[(N<<1)+3];
int fe[N+3];
int fa[N+3];
llong a[N+3];
int dgr[N+3];
int n,en;
bool ans;

void addedge(int u,int v)
{
	dgr[u]++;
	en++; e[en].v = v;
	e[en].nxt = fe[u]; fe[u] = en;
}

void dfs(int u)
{
	if(dgr[u]==1) {return;}
	llong tmp = 0ll,mx = 0ll;
	for(int i=fe[u]; i; i=e[i].nxt)
	{
		int v = e[i].v;
		if(v==fa[u]) continue;
		fa[v] = u;
		dfs(v);
		tmp += a[v];
		mx = max(mx,a[v]);
	}
	if(tmp<a[u]) {ans = false;}
	llong lim = min(tmp-mx,tmp/2);
	tmp -= a[u];
	if(tmp>lim) {ans = false;}
	a[u] -= tmp;
//	printf("a[%d]=%lld\n",u,a[u]);
}

int main()
{
	scanf("%d",&n);
	for(int i=1; i<=n; i++) scanf("%d",&a[i]);
	for(int i=1; i<n; i++)
	{
		int u,v; scanf("%d%d",&u,&v);
		addedge(u,v); addedge(v,u);
	}
	if(n==2) {if(a[1]==a[2]) puts("YES"); else puts("NO"); return 0;}
	int rtn = 1; while(dgr[rtn]==1) rtn++;
	ans = true; dfs(rtn);
	if(a[rtn]!=0) {ans = false;}
	if(ans==false) puts("NO");
	else puts("YES");
	return 0;
}