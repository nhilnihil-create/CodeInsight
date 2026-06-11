#include <iostream>
#include <vector>
using namespace std;

const int N = 100 * 1000 + 5;
int n, k, ans;

int a[N];
vector <int> adj[N];
int g[N];
bool mark[N];
bool b[N];

void dfs(int v) {
	mark[v] = true;
	g[v] = 1;
	for (auto u : adj[v]) {
		if (!mark[u]) {
		//	h[u] = h[v] + 1;
			dfs(u);
			g[v] = max(g[v], g[u] + 1);
		}
	}
	if (g[v] == k && !b[v]) {
		ans++;
		g[v] = 0;
	}
//	if (h[v] % (k + 1) == 0) {
//		ans++;
//	}
}
int main() {
	cin >> n >> k;
	b[1] = true;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		adj[a[i]].push_back(i);
		if (a[i] == 1) {
			b[i] = true;
		}
	}
	dfs(1);
	if (a[1] != 1) {
		ans++;
	}
	cout << ans << endl;
	return 0;
}
