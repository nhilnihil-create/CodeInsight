# include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn(1e5 + 5);

int n, a[maxn], d[maxn];
ll up[maxn];
vector <int> son[maxn];

inline void Add(int u, int v) {
	son[u].push_back(v), son[v].push_back(u), ++d[u], ++d[v];
}

# define Orzyyb puts("NO"), exit(0)
# define Orzzsy puts("YES"), exit(0)

void Dfs(int u, int ff) {
	ll sum = 0, mx = 0;
	if (d[u] == 1) {
		up[u] = a[u];
		return;
	}
	for (auto v : son[u])
		if (v != ff) Dfs(v, u), mx = max(up[v], mx), sum += up[v];
	if (sum - mx <= mx) mx = sum - mx;
	else mx = sum / 2;
	if (a[u] > sum || a[u] < sum - mx) Orzyyb;
	mx = min(mx, sum - a[u]), sum -= mx << 1, up[u] = sum;
	if (up[u] < 0) Orzyyb;
	if (!ff && up[u]) Orzyyb;
}

int main() {
	int i, u, v;
	scanf("%d", &n);
	for (i = 1; i <= n; ++i) scanf("%d", &a[i]);
	if (n == 2) {
		if (a[1] == a[2]) Orzzsy;
		else Orzyyb;
	}
	for (i = 1; i < n; ++i) scanf("%d%d", &u, &v), Add(u, v);
	for (i = 1; i <= n; ++i) if (d[i] > 1) Dfs(i, 0), Orzzsy;
	return 0;
}