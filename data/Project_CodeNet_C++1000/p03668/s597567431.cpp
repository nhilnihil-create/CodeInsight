#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 100, MOD = 1000 * 1000 * 1000 + 7;

int n, dp[N];
vector<int> nei[N];

void input() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		nei[--u].push_back(--v);
		nei[v].push_back(u);
	}
}

void dfs(int v = 0, int par = -1) {
	for (int u: nei[v])
		if (u ^ par) {
			dfs(u, v);
			dp[v] ^= ++dp[u];
		}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	input();
	dfs();
	cout << (dp[0] == 0? "Bob\n": "Alice\n");
}
