#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int head[100005], tot, n, m, q, v[100005], d[100005], c[100005], ou[100005], maxd[100005];
struct edge {
	int to, nxt;
} G[300005];

inline void add(int u, int v) {
	tot++;
	G[tot].to = v;
	G[tot].nxt = head[u];
	head[u] = tot;
}

void dfs(int un, int ds, int c) {
	if(maxd[un] >= ds) return;
	if(!ou[un]) ou[un] = c;
	if(!ds) return;
	maxd[un] = ds;
	for (int i = head[un]; i; i = G[i].nxt) dfs(G[i].to, ds - 1, c);
}

int main() {
	scanf ("%d %d", &n, &m);
	int u, vd;
	for (int i = 1; i <= m; i++) {
		scanf ("%d %d", &u, &vd);
		add(u, vd); add(vd, u);
	}
	memset (maxd, -1, sizeof (maxd));
	scanf ("%d", &q);
	for (int i = 1; i <= q; i++) scanf ("%d %d %d", &v[i], &d[i], &c[i]);
	for (int i = q; i >= 1; i--) dfs(v[i], d[i], c[i]);
	for (int i = 1; i <= n; i++) printf ("%d\n", ou[i]);
	return 0;
}