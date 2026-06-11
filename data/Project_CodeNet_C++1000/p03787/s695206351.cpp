#include <iostream>
#include <vector>
#define int long long
using namespace std;

const int N = 100 * 1000 + 5;
int x, y, z;

vector <int> adj[N];
int part[N];
bool dfs(int v) {
	bool b = true;
	for (auto u : adj[v]) {
		if (part[u] == part[v])
			b = false;
		if (part[u] == 0) {
			part[u] = 3 - part[v];
			if (!dfs(u)) {
				b = false;
			}
		}
	}
	return b;
}
void check(int v) {
	if (part[v] != 0)
		return;
	part[v] = 1;
	if (adj[v].size() == 0) {
		z++;
		return;
	}
	if (dfs(v)) {
		y++;
	}
	else {
		x++;
	}
}
int32_t main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		check(i);
	}
//	cout << x << " " << y << " " << z << endl;
	long long ans = (long long) 1ll * (x + y) * (x + y) + 1ll * y * y + 2ll * n * z - 1ll * z * z;
	cout << ans << endl;
	return 0;
}
