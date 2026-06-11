#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;

int n;
long long arr[MAXN];
vector<int> adj[MAXN];
bool CANT = false;

long long dfs(int v, int par = 0) {
	long long all = 0, mx = 0;
	for (auto e : adj[v]) 
		if (e != par) {
			long long g = dfs(e, v);
			all += g;
			mx = max(mx, g);
		}
	if (adj[v].size() == 1)
		return arr[v];
	if (all < arr[v]) {
		CANT = true;
		return 0;
	}
	long long needed = all - arr[v];
	long long nmat = 0;
	if ((all - mx) < mx)
		nmat = all - mx;
	else
		nmat = all / 2;
	if (nmat < needed) {
		CANT = true;
		return 0;
	}
	return all - 2 * needed;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	if (n == 2) {
		if (arr[1] == arr[2])
			return cout << "YES\n", 0;
		return cout << "NO\n", 0;
	}
	for (int i = 1; i <= n; i++)
		if (adj[i].size() > 1) {
			if (dfs(i) || CANT) 
				return cout << "NO\n", 0;
			return cout << "YES\n", 0;
		}
	return 0;
}