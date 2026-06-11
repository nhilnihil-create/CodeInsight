#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)x.size()
//#define int ll

const int N = 2010;
vector<int> g[N];
int dp[N][N], pref1[N], pref2[N], new_dp[N], mx_h[N], sub[N], k;

void dfs(int v, int p = 0) {
	int cnt = 0;
	sub[v] = 1;
	dp[v][0] = 1;
	mx_h[v] = 0;
	for (auto u : g[v]) {
		if (u != p) {
			dfs(u, v);
			//sub[v] += sub[u];
			cnt++;
			if (cnt == 1) {
				for (int i = 0; i <= mx_h[u]; i++) {
					dp[v][i + 1] = 1 + dp[u][i];
				}
			}
			else {
				pref1[0] = dp[v][0];
				for (int i = 1; i <= mx_h[v]; i++) {
					pref1[i] = max(pref1[i - 1], dp[v][i]);
				}
				pref2[0] = dp[u][0];
				for (int i = 1; i <= mx_h[u]; i++) {
					pref2[i] = max(pref2[i - 1], dp[u][i]);
				}
				for (int i = 1; i <= k; i++) {
					new_dp[i] = 0;
				}
				for (int i = 1; i <= min(mx_h[v], k); i++) {
					new_dp[i] = dp[v][i] + pref2[min(mx_h[u], min(i - 1, k - i - 1))];
				}
				for (int i = 1; i <= min(mx_h[u] + 1, k); i++) {
					new_dp[i] = max(new_dp[i], dp[u][i - 1] + pref1[min(mx_h[v], min(i, k - i))]);
				}
				for (int i = 1; i <= max(mx_h[v], mx_h[u] + 1); i++) {
					dp[v][i] = max(dp[v][i], new_dp[i]);
				}
			}
			mx_h[v] = max(mx_h[v], mx_h[u] + 1);
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n >> k;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(1);
	int ans = n;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= min(mx_h[i], k); j++) {
			ans = min(ans, n - dp[i][j]);
		}
	}
	cout << ans << '\n';
}	