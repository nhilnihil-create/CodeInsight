#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int Maxn = 111111;
struct Edge {
	int v, id;
	Edge *nxt;
} pool[Maxn*2], *tree[Maxn], *tail = pool;
inline void addedge(const int &u, const int &v, const int &id) {
	tail->v = v, tail->id = id;
	tail->nxt = tree[u], tree[u] = tail++;
}

int n, a[Maxn], w[Maxn];
bool isleaf[Maxn];

void dfs(int u, int fa, int lastid) {
	w[lastid] = a[u];
	isleaf[u] = true;
	for (Edge *p = tree[u]; p; p = p->nxt) {
		if (p->v != fa) {
			isleaf[u] = false;
			dfs(p->v, u, p->id);
			w[lastid] -= w[p->id];
		}
	}
	if (!isleaf[u]) {
		w[lastid] += a[u];
	}
}
void solve() {
	if (n == 2) {
		if (a[1] == a[2]) {
			puts("YES");
		} else {
			puts("NO");
		}
		return;
	}
	for (int i = 1, cnum; i <= n; ++i) {
		cnum = 0;
		for (Edge *p = tree[i]; p; p = p->nxt) {
			++cnum;
		}
		if (cnum > 1) {
			dfs(i, 0, 0);
			break;
		}
	}
	if (w[0] != 0) {
		puts("NO");
		return;
	}
	for (int i = 1; i < n; ++i) {
		if (w[i] < 0) {
			puts("NO");
			return;
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (!isleaf[i]) {
			LL tot = 0;
			for (Edge *p = tree[i]; p; p = p->nxt) {
				tot += w[p->id];
			}
			for (Edge *p = tree[i]; p; p = p->nxt) {
				if (w[p->id] > tot/2) {
					puts("NO");
					return;
				}
			}
		}
	}
	puts("YES");
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i){
		scanf("%d", &a[i]);
	}
	for (int i = 1, x, y; i < n; ++i) {
		scanf("%d%d", &x, &y);
		addedge(x, y, i), addedge(y, x, i);
	}
	solve();
	return 0;
}