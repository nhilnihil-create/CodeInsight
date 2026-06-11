#include <bits/stdc++.h>

using namespace std;

const int maxn = 100010;

int n = 0;

int l[maxn], a[maxn], deg[maxn], val[maxn], e = 0, rt = 0, ok = 1;

struct Edge {
	int v, x;
} E[maxn << 1];

inline void addEdge(int u, int v) {
	E[e].v = v; E[e].x = l[u]; l[u] = e++;
}

void dfs(int u, int f) {
	if (deg[u] == 1) {
		val[u] = a[u];
		return;
	}
	int s = 0, mx = 0;
	for (int p = l[u]; p >= 0; p = E[p].x) {
		int v = E[p].v;
		if (v != f) {
			dfs(v, u);
			s += val[v];
			mx = max(mx, val[v]);
		}
	}
	if (!ok) return;
	int c = s - a[u];
	if (c < 0 || 2*c > s) {
		ok = 0;
		return;
	}
	val[u] = s - 2*c;
	if (mx > s - mx) {
		if (c > s - mx) {
			ok = 0;
			return;
		}
	}
}

int main() {
	memset(l, -1, sizeof(l));
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i < n; i++) {
		int u, v; scanf("%d%d", &u, &v);
		addEdge(u, v);
		addEdge(v, u);
		deg[u] ++;
		deg[v] ++;
	}
	if (n == 2) {
		if (a[1] == a[2]) puts("YES");
		else puts("NO");
		return 0;
	}
	for (int i = 1; i <= n; i++) if (deg[i] > 1) rt = i;
	dfs(rt, 0);
	if (ok && !val[rt]) puts("YES");
	else puts("NO");
	return 0;
}