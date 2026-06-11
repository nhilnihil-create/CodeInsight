#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n;
int a[N];
int rem[N];
vector<int> G[N];

void dfs(int u, int p) {
	int mx = 0;
	rem[u] = (G[u].size() == 1 ? a[u] : 0);
	for (int v : G[u]) if (v != p) {
		dfs(v, u);
		rem[u] += rem[v];
		mx = max(mx, rem[v]);
	}
	if (a[u] > rem[u]) { printf("NO\n"); exit(0); }
	int need = rem[u] - a[u]; // number of needed pairs

	if (mx > rem[u] / 2) mx = rem[u] - mx;
	else mx = rem[u] / 2;

	if (mx < need) { printf("NO\n"); exit(0); }

	rem[u] -= 2 * need;
	a[u] = 0;
	//cerr << u << ' ' << rem[u] << endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	if (n == 2) {
		if (a[1] == a[2]) return printf("YES\n"), 0;
		else return printf("NO\n"), 0;
	}
	for (int i = 1; i < n; ++i) {
		int u, v; cin >> u >> v;
		G[u].push_back(v); G[v].push_back(u);
	}
	int rt;
	for (int i = 1; i <= n; ++i) if (G[i].size() > 1) rt = i;
	dfs(rt, 0);

	if (!rem[rt]) printf("YES\n"); else printf("NO\n");
}