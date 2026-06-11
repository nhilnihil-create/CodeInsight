#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = (1e6) + 6, mod = 0;
int mark[N];
vector<int> adj[N];

int main() {
	int n, m;
	cin >> n >> m;
	for (int j = 0; j < m; ++j) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<int> a, b;
	a.push_back(0);
	mark[0] = 1;
	int cur = 0;
	while (true) {
		int flag = 1;
		for (int u : adj[cur]) if (!mark[u]) {
			mark[u] = 1;
			a.push_back(u);
			cur = u;
			flag = 0;
			break;
		}
		if (flag) break;
	}
	cur = 0;
	while (true) {
		int flag = 1;
		for (int u : adj[cur]) if (!mark[u]) {
			mark[u] = 1;
			b.push_back(u);
			cur = u;
			flag = 0;
			break;
		}
		if (flag) break;
	}
	reverse(b.begin(), b.end());
	for (int x : a) b.push_back(x);
	cout << (int)b.size() << endl;
	for (int x : b) cout << x + 1 << ' ';
	cout << endl;
    return 0;
}
