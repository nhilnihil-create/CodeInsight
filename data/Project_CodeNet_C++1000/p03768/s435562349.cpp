#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

vector <int> G[N];
int rec[N], color[N], ver[N], d[N], c[N];

void dfs(int x, int dist, int col){
	if (!color[x]) color[x] = col;
	if (~rec[x] && dist <= rec[x]) return;
	rec[x] = dist;
	if (dist == 0) return;
	for (int i = 0; i < G[x].size(); i++) dfs(G[x][i], dist - 1, col);
}

int main(){
	int n, m, q, u, v;
	scanf("%d %d",&n,&m);
	for (int i = 1; i <= m; i++){
		scanf("%d %d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	memset(rec, -1, sizeof(rec));
	memset(color, 0, sizeof(color));
	scanf("%d",&q);
	for (int i = 1; i <= q; i++) scanf("%d %d %d",&ver[i],&d[i],&c[i]);
	for (int i = q; i >= 1; i--) dfs(ver[i], d[i], c[i]);
	for (int i = 1; i <= n; i++) printf("%d\n", color[i]);
	return 0;
}