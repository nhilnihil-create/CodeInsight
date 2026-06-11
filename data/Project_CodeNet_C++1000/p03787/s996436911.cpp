#include <bits/stdc++.h>

using namespace std;

const int maxn = 100010;
const int maxm = 200010;

int l[maxn], e, ok = 0;
int n, m;
int vis[maxn], col[maxn];
int cnt = 0, cnt_b = 0, cnt1 = 0, c = 0;

struct Edge {
	int v, x;
} E[maxm<<1];

inline void addEdge(int u, int v) {
	E[e].v = v; E[e].x = l[u]; l[u] = e++;
}

void dfs(int u) {
	vis[u] = 1; ++ c;
	for (int p = l[u]; p >= 0; p = E[p].x) {
		int v = E[p].v;
		if (!vis[v]) {
			col[v] = (col[u] ^ 1);
			dfs(v);
		} else if (col[v] != (col[u] ^ 1)) ok = 0;
	}
}

int main() {
	memset(l, -1, sizeof(l));
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		addEdge(u, v);
		addEdge(v, u);
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			ok = 1;
			c = 0;
			dfs(i);
			if (c == 1) {
				++ cnt1;
				continue;
			}
			++ cnt;
			if (ok) cnt_b ++;
		}
	}
	printf("%lld\n", 1LL*cnt*cnt + 1LL*cnt_b*cnt_b + 1LL*n*n - 1LL*(n-cnt1)*(n-cnt1));
	return 0;
}