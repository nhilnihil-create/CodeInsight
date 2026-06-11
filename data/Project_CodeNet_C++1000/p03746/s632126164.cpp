#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 10, mod = 1e9 + 7;
typedef long long ll;
typedef pair <ll, ll> pii;

vector <int> adj[N];
int h[N];
vector <int> tour;

void dfs_2 (int v, int p) {
	tour.push_back(v);
	for (auto u : adj[v]) {
		if (u == p)	continue;
		if (h[u] == 1e7) {
			h[u] = h[v] + 1, dfs_2(u, v);
			break;
		}
	}
	return;
}

void dfs (int v, int p = -1) {
	tour.push_back(v);
	for (auto u : adj[v]) {
		if (u == p)	continue;
		if (h[u] == 1e7) {
			h[u] = h[v] + 1, dfs(u, v);
			break;
		}
	}
	if (v == 0) {
		for (auto u : adj[v]) {
			if(h[u] == 1e7) {
				reverse(tour.begin(), tour.end());
				h[u] = 1;
				dfs_2(u, v);
				return;
			}
		} 
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int v, u;
		cin >> v >> u;
		v--, u--;
		adj[v].push_back(u), adj[u].push_back(v);
	}
	fill(h, h + n, 1e7);
	h[0] = 0;
	dfs(0);
	cout << tour.size() << "\n";
	while (!tour.empty()) {
		cout << tour.back() + 1 << " ";
		tour.pop_back();
	}
	cout << "\n";
}