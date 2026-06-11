#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n;
int d[N];
vector<int> G[N];
bool bipartite;
bool c[2];
int cnt;

int m;
int a[N];
int b[N];
int t[N];

long long ans;

void dfs(int u) {
	++cnt;
	for (int v : G[u]) {
		if (d[v] == -1) d[v] = (d[u] ^ 1), c[d[v]] = 1, dfs(v);
		else if (d[v] == d[u]) bipartite = true;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	memset(d, -1, sizeof d);
	while(m--) {
		int u, v; cin >> u >> v;
		G[u].push_back(v); G[v].push_back(u);
	}

	m = 0;
	for (int i = 1; i <= n; ++i) if (d[i] == -1) {
		bipartite = false; d[i] = 0; c[0] = 1; c[1] = 0; cnt = 0; dfs(i);
		++m; a[m] = bipartite; b[m] = c[0] + c[1]; t[m] = cnt;
	}

	int full0 = 0, full1 = 0, full = 0, cnt_invalid = 0; 
	for (int i = 1; i <= m; ++i) {
		full1 += (b[i] == 2 ? 1 : 0);
		if (b[i] == 2) full0 += (a[i] == 1 ? 1 : 2);
		full += t[i];
		if (b[i] == 1) cnt_invalid++;
	}

	for (int i = 1; i <= m; ++i) {
		//cerr << t[i] << ' ' << a[i] << endl;
		if (a[i] == 1) {
			ans += full1 + 1LL * cnt_invalid * t[i];
		} else {
			if (b[i] == 1) ans += full;
			else ans += full0 + 1LL * cnt_invalid * t[i];
		}
		//cerr << i << ' ' << ans << endl;
	}
	cout << ans << endl;
}