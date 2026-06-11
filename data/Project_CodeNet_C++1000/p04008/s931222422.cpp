#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, k, a[N], dep[N], L[N], R[N], dfc, pa[17][N];
int bit[N];
inline void add(int i, int x) {
	while (i <= n) {
		bit[i] += x;
		i += i & -i;
	}
}
inline int sum(int i) {
	int res = 0;
	while (i > 0) {
		res += bit[i];
		i -= i & -i;
	}
	return res;
}
pair<int, int> ar[N];
vector<int> G[N];
void dfs(int u, int depth) {
	dep[u] = depth;
	L[u] = ++dfc;
	ar[dfc] = make_pair(dep[u], u);
	for (int v : G[u]) {
		dfs(v, depth + 1);
	}
	R[u] = dfc;
}
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	int ans = (a[1] != 1);
	pa[0][1] = 0;
	for (int i = 2; i <= n; i++) {
		G[a[i]].push_back(i);
		pa[0][i] = a[i];
	}
	for (int i = 1; i < 17; i++)
		for (int u = 1; u <= n; u++)
			pa[i][u] = pa[i - 1][pa[i - 1][u]];
	dfs(1, 0);
	sort(ar + 1, ar + 1 + n);
	for (int _ = n; _ >= 1; _--) {
		int u = ar[_].second;
		if (dep[u] <= k) break;
		if (sum(L[u])) continue;
		ans++;
		int v = u;
		for (int i = 0; i < 17; i++) if ((k - 1) >> i & 1) v = pa[i][v];
		add(L[v], 1);
		add(R[v] + 1, -1);
	}
	printf("%d\n", ans);
	return 0;
}