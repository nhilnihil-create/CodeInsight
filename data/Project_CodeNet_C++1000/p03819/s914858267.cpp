#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n, m;
int num;
int head[100010], to[300010], nxt[300010], ind;
inline void addedge (int u, int v) { ind++, to[ind] = v, nxt[ind] = head[u], head[u] = ind; }
int cnt, root[100010];
struct T { int num, ch[2]; } t[6000010];
inline void build_tree (int p, int l, int r) {
	t[p].num = 0;
	if (l == r) return;
	int mid = (l + r) >> 1;
	t[p].ch[0] = ++cnt;
	build_tree (cnt, l, mid);
	t[p].ch[1] = ++cnt;
	build_tree (cnt, mid + 1, r);
}
inline int add (int p, int l, int r, int x) {
	if (l == r) { cnt++, t[cnt] = t[p], t[cnt].num++; return cnt; }
	int mid = (l + r) >> 1;
	int pos = ++cnt;
	t[pos] = t[p]; t[pos].num++;
	if (x <= mid) t[pos].ch[0] = add(t[p].ch[0], l, mid, x);
	else t[pos].ch[1] = add (t[p].ch[1], mid + 1, r, x);
	return pos;
}
int ans[100010];
inline int query (int p, int l, int r, int ll, int rr) {
	if (l >= ll && r <= rr) return t[p].num;
	int mid = (l + r) >> 1;
	int res = 0;
	if (ll <= mid) res += query (t[p].ch[0], l, mid, ll, rr);
	if (rr > mid) res += query (t[p].ch[1], mid + 1, r, ll, rr);
	return res;
}
int main () {
	scanf ("%d%d", &n, &m);
	root[0] = 1; cnt = 1; build_tree (1, 1, m);
	for (int i = 1; i <= n; i++) {
		int l, r;
		scanf ("%d%d", &l, &r);
		if (l == 0) num++, n--, i--;
		else addedge (l, r);
	}
	for (int i = 1; i <= m; i++) {
		root[i] = root[i - 1];
		for (int e = head[i]; e; e = nxt[e]) {
			int v = to[e];
			root[i] = add (root[i], 1, m, v);
		}
	}
	for (int i = 2; i <= m; i++)
		for (int j = i; j <= m; j += i)
			ans[i] += query (root[j], 1, m, j, m) - query (root[j - i], 1, m, j, m);
	printf ("%d\n", n + num);
	for (int i = 2; i <= m; i++) printf ("%d\n", ans[i] + num);
	return 0;
}