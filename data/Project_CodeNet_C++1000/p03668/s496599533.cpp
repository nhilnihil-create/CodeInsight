#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5+5;

int n, s[MAXN];
vector<int> g[MAXN];

int dfs(int v, int f = -1) {
	for (int u : g[v])
		if (u != f)
			s[v] ^= (1 + dfs(u, v));
	return s[v];
}

int main() {
	cin >> n;
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	if (dfs(0) == 0) {
		cout << "Bob\n";
	} else
		cout << "Alice\n";
}