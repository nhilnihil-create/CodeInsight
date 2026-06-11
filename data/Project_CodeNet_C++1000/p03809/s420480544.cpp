#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100003;
struct Edge {
	int to, nxt;
	Edge() {}
	Edge(int to, int nxt):to(to), nxt(nxt) {}
}e[MAXN << 1];
int h[MAXN], p;
int w[MAXN], du[MAXN], fa[MAXN];
int n, rt;
bool fg = 1;

inline void add_edge(int a, int b) {
	e[++p] = Edge(b, h[a]); h[a] = p;
	e[++p] = Edge(a, h[b]); h[b] = p;
}

int dfs(int u) {
	int s = 0, mx = 0;
	bool son = 0;
	for(int i = h[u]; i; i = e[i].nxt) {
		int v = e[i].to;
		if(v == fa[u]) continue;
		son = 1;
		fa[v] = u;
		int cur = dfs(v);
		s += cur;
		mx = max(mx, cur);
	}
	if(!son) return w[u];
	if(w[u] > s || w[u] < mx || 2 * w[u] < s) {
		fg = 0;
		return 0;
	}
	return 2 * w[u] - s;
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", w + i);
	for(int i = 1, a, b; i < n; i++) {
		scanf("%d%d", &a, &b);
		add_edge(a, b);
		du[a]++; du[b]++;
	}
	if(n == 2) {
		if(w[1] == w[2]) puts("YES");
		else puts("NO");
		return 0;
	}
	int res = 0;
	for(int i = 1; i <= n; i++) if(du[i] > 1) {
		res = dfs(i);
		break;
	}
	if(res == 0 && fg == 1) puts("YES");
	else puts("NO");
	return 0;
}
