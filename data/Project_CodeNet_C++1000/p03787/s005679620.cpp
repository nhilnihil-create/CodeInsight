#include <bits/stdc++.h>
using namespace std;

int n, m, bp, nbp, lonely;
vector<vector<int> > g;
vector<int> color;
bool dfs(int u, int curr = 0) {
	color[u] = curr;
	bool ret = true;
	for(int v: g[u]) {
		if(color[v] == -1) ret &= dfs(v, curr ^ 1);
		else if(color[v] != curr ^ 1) ret = false;
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	g.resize(n);
	color.assign(n, -1);
	for(int i = 0, u, v; i < m; i++) {
		cin >> u >> v;
		g[u-1].push_back(v-1);
		g[v-1].push_back(u-1);
	}
	for(int i = 0; i < n; i++) if(color[i] == -1) {
		if(g[i].empty()) {
			lonely++;
			continue;
		}
		bool res = dfs(i);
		bp += res;
		nbp += !res;
	}
	cout << 1ll*n*n - 1ll*(n-lonely)*(n-lonely) + 1ll*(bp+nbp)*(bp+nbp) + 1ll*bp*bp;
}
