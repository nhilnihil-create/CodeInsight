#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5+5;

int n, m;
vector<int> g[MAXN];
int vis[MAXN];
int bip = 1;
ll ct1 = 0, ct2 = 0, one = 0;
int ct = 0;

void dfs(int v, int c) {
	vis[v] = c;
	ct++;

	for (int u : g[v]) {
		if (vis[u] == 0)
			dfs(u, 3-c);
		if (vis[u] != 3-vis[v])
			bip = 0;
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int u, v; cin >> u >> v;
		u--; v--;
		g[v].push_back(u);
		g[u].push_back(v);
	}

	ll ans = n*n;

	for (int i = 0; i < n; ++i) {
		ct = 0; bip = 1;
		if (vis[i] == 0) {
			dfs(i, 1);
			if (ct == 1)
				one++;
			else if (bip == 1)
				ct2++;
			else
				ct1++;
		}
	}

	ll s = one + ct1 + ct2;

	cout << 2*one*n - one*one + 2*ct1*ct2 + ct1*ct1 + 2*ct2*ct2 << endl;
}