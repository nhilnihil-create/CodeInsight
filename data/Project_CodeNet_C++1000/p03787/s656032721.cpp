#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int MAXN=110000;
int r[MAXN];
vector<int> g[MAXN];
bool dfs(int u, int f, int c)
{
	if (~r[u]) return c==r[u];
	r[u]=c; bool k=1;
	for (int i=0; i<g[u].size(); i++)
	{
		int v=g[u][i];
		k&=dfs(v, u, c^1);
	}
	return k;
}
int main()
{
//	freopen("C.in", "r", stdin);
//	freopen("C.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i=1; i<=m; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	memset(r, -1, sizeof r);
	int p=0, c=0, d=0;
	for (int i=1; i<=n; i++)
		if (r[i]==-1)
		{
			if (g[i].size()==0) p++;
			else if (dfs(i, 0, 0)) c++;
			else d++;
		}
	printf("%lld\n", 1ll*p*n+1ll*(n-p)*p+2ll*c*c+1ll*d*(d+c*2));
	return 0;
}