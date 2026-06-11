#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, k, ans, a[N];
vector<int> g[N];

int dfs(int u, int fa) {
	int r = 1;
	for(auto v : g[u]) {
		if(v == fa) continue;
		r = max(1 + dfs(v, u), r);
	}
	if(r == k && fa)
		return ans += a[u] != 1, 0;
	return r;
}

int main() {
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
		if(i == 1) continue;
		g[a[i]].push_back(i);
		g[i].push_back(a[i]);
	}
	dfs(1, 0);
	if(a[1] != 1) ++ans;
	cout << ans << '\n';
	return 0;
}
