#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <set>

#define lowbit(x) (x&(-x))
#define MAX(a,b) (a<b?b:a)
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int N = 2e5;
const int maxn = 1e5 + 5;
ll mod = 1e9 + 7;

struct Edge
{
	int u, v, nxt;
	Edge(int _u = 0, int _v = 0, int _nxt = 0)
	{
		u = _u;
		v = _v;
		nxt = _nxt;
	}
}edg[maxn << 1];
int n, m, q;
int g[maxn], ecnt;
struct QRY
{
	int u, d, c;
}qry[maxn];

int vis[maxn][11],col[maxn];
void color(int u, int d, int c)
{
	if (vis[u][d]) return;
	vis[u][d] = 1;
	if (!col[u]) col[u] = c;
	if (!d) return;
	
	for (int i = g[u]; ~i; i = edg[i].nxt)
	{
		int &v = edg[i].v;
		color(v, d - 1, c);
	}
}

int main()
{
	memset(g, ecnt = -1, sizeof(g));
	scanf("%d%d", &n, &m);
	while (m--)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		edg[++ecnt] = Edge(u, v, g[u]); g[u] = ecnt;
		edg[++ecnt] = Edge(v, u, g[v]); g[v] = ecnt;
	}
	scanf("%d", &q);
	for (int i = 1; i <= q; i++) scanf("%d%d%d", &qry[i].u, &qry[i].d, &qry[i].c);

	while (q)
	{
		color(qry[q].u, qry[q].d, qry[q].c);
		q--;
	}
	for (int i = 1; i <= n; i++) printf("%d\n", col[i]);
}
