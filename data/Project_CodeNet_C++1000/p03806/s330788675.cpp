#include <bits/stdc++.h>
using namespace std;
using ll = long long;

enum { N = 40 , A = 10, INF = 10000000 };
int n, ma, mb, sa = 0, sb = 0, sc = 0, mc = INF;
vector<int> a(N + 5), b(N + 5), c(N + 5);
vector<vector<vector<int>>> dp(N+1, vector<vector<int>>(A*N+1, vector<int> (A*N+1, INF)));

void solve() {
	dp[0][0][0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= N * A; j++) {
			for (int k = 0; k <= N * A; k++) {
				if (dp[i][j][k]==INF) continue;
				dp[i+1][j][k] = min(dp[i+1][j][k], dp[i][j][k]);
				dp[i+1][j+a[i]][k+b[i]] = min(dp[i+1][j+a[i]][k+b[i]], dp[i][j][k]+c[i]);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> ma >> mb;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i] >> c[i];
	}
	solve();
	for (int j = 1; j <= N*A; j++) {
		for (int k = 1; k <= N*A; k++) {
			if (k*ma == j*mb) mc = min(mc, dp[n][j][k]);
		}
	}
	if (mc == INF) mc = -1;
	cout << mc << endl;
	return 0;
}