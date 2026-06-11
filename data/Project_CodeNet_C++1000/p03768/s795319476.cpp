#include <bits/stdc++.h>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define N 1000005
using namespace std;

int n, m, q, dp[15][N], u[N], a[N], v[N], d[N], c[N];
vector < int > g[N];

void yap(int v, int d, int c){
	if(dp[d][v])
		return;
	dp[d][v] = 1;
	if(!u[v]){
		a[v] = c;
		u[v] = 1;
	}
	if(d == 0)
		return;
	for(int i = 0; i < g[v].size(); i++)
		yap(g[v][i], d - 1, c);
}

int main() {
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	scanf("%d %d",&n ,&m);
	while(m--){
		int u, v;
		scanf("%d %d",&u ,&v);
		g[u].pb(v);
		g[v].pb(u);
	}
	scanf("%d",&q);
	for(int i = 1; i <= q; i++)
		scanf("%d %d %d",v + i, d + i, c + i);
	for(int i = q; i >= 1; i--)
		yap(v[i], d[i], c[i]);
	for(int i = 1; i <= n; i++)
		printf("%d\n", a[i]);
	return 0;
}