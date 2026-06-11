#include <iostream>
#include <vector>
using namespace std;

const int N = 100 * 1000 + 5;

vector <int> adj[N];

int t[N];
int d[N];
int c[N];
int dp[N][12];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int q;
	cin >> q;
	for (int i = 1; i <= q; i++) {
		cin >> t[i] >> d[i] >> c[i];
		dp[t[i]][d[i]] = max(dp[t[i]][d[i]], i);
	}
	for (int j = 9; j >= 0; j--) {
		for (int i = 1; i <= n; i++) {
			dp[i][j] = max(dp[i][j + 1], dp[i][j]);
			for (auto u : adj[i]) {
				dp[i][j] = max(dp[i][j], dp[u][j + 1]);
			}
		//	cout << i << " " << j << " " << dp[i][j] << endl;
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << c[dp[i][0]] << endl;
	}
	return 0;
}
