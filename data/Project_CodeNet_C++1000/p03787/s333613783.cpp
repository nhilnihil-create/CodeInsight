#include <cstdio>
#define ll long long
#define rep(i,j,k) for (i=j;i<=k;i++)
using namespace std;
const int N=1e5+5,M=2e5+5;
int n,m,u,v,i,j;
int En,flg,V,vis[N],col[N],fst[N],nxt[M*2],to[M*2];
ll ans,unit,even,odd;
void add(int u,int v) {
	En++; nxt[En]=fst[u]; fst[u]=En; to[En]=v;
}
void dfs(int x,int p)
{
	int j,v;
	V++; col[x]=p; vis[x]=1;
	for (j=fst[x];j;j=nxt[j])
	{
		v=to[j];
		if (vis[v]) {
			if (col[v]==col[x]) flg=1;
			continue;
		}
		dfs(v,p^1);
	}
}
int main()
{
//	freopen("sqr.in","r",stdin);
//	freopen("sqr.out","w",stdout);
	scanf("%d%d",&n,&m);
	rep(i,1,m)
	{
		scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	rep(i,1,n)
	if (!vis[i])
	{
		V=0; flg=0;
		dfs(i,0);
		if (V==1) unit++;
		else if (flg) odd++;
		else even++;
	}
	ans=2*unit*n-unit*unit+2*odd*(odd+even)-odd*odd+2*even*even;
	printf("%lld\n",ans);
	return 0;
}