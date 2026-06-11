#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define f first
#define s second
#define mp make_pair
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
const int mod = (int)1e9 + 7;
vector<int> g[2020];
int dp[2020][2020];
int sz[2020];
int tmp[2020];
int D[2020];
int k;
int n;
int ans = mod;
void dfs(int v, int p) {
	sz[v] = 1;
	dp[v][0] = 0;
	for(int i = 1; i <= n; i++) dp[v][i] = mod;
	for(int to: g[v]) {
		if(to == p) continue;
		dfs(to, v);
		for(int i = 0; i <= sz[v] + sz[to]; i++) {
			tmp[i] = dp[v][i];
			dp[v][i] = mod;
		}
		for(int i = 0; i <= sz[v]; i++) {
			for(int j = 0; j <= sz[to]; j++) {
				//dp[v][i] = min(tmp[i]+dp[to][j] + 1, dp[v][i]);
				if(i + j + 1 <= k) {
					dp[v][max(i, j+1)] = min(tmp[i] + dp[to][j], dp[v][max(i, j+1)]);
				}
			}
			dp[v][i] = min(tmp[i] + sz[to], dp[v][i]);
		}
		sz[v] += sz[to];
	}
	for(int i = 0; i <= k; i++) ans = min(ans, dp[v][i]+n-sz[v]);
}

int main () {
	cin >> n >> k;
	for(int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	dfs(1, -1);
	//for(int i = 0; i <= k; i++) ans = min(ans, dp[1][i]);
	cout << ans << "\n";
 	return 0;
}

