#include"bits/stdc++.h"
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
const long long inf = 1ll << 61;
const long long mod = 998244353;
vector<int>G[100006];
int a[100006];
int dp[100006];
int ng;

bool pairnum(vector<int>V, int N) {
	sort(V.begin(), V.end());
	int s = 0;
	rep(i, V.size() - 1) {
		s += V[i];
	}
	int r = V[V.size() - 1];
	if (r > s)r = s;
	return (r + s) / 2 >= N;
}

int dfs(int now, int par) {//下から何本のパスを上に引き上げられるか
	if (dp[now] != -inf)return dp[now];
	vector<int>V; int S = 0;
	for (int e : G[now]) {
		if (e==par)continue;
		V.push_back(dfs(e, now));
		S += dp[e];
	}
	if (V.empty()) {
		return dp[now] = a[now];
	}

	int P = S - a[now], Q = a[now] - P;
	if (P < 0 || Q < 0)ng++;
	if (!pairnum(V,P))ng++;
	return dp[now] = Q;
}
signed main() {
	int n; cin >> n;
	rep(i, n)cin >> a[i];
	rep(i, n - 1) {
		int x, y; cin >> x >> y;
		x--; y--;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	rep(i, n)dp[i] = -inf;
	int par;
	rep(i, n) {
		if (G[i].size() == 1)par = i;
	}
	dfs(par, -1);
	if (ng)puts("NO");
	else puts("YES");
}