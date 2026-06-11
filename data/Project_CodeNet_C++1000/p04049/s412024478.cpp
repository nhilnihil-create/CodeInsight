#define _USE_MATH_DEFINES
#include "bits/stdc++.h"
#define rep(i,a,b) for (int i = (a); i < (b); i++)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
typedef complex<double> com;
const int mod = 1e9 + 7;
const int MOD = 998244353;
const int inf = 2e9;

int n, k, cnt;
vector<P> e; vector<vector<int>> g;
void dfs(int now, int u, int cost) {
	if (cost > k / 2) cnt++;
	for (int v : g[now]) {
		if (v != u) dfs(v, now, cost + 1);
	}
}

int main() {
	cin >> n >> k;
	g.resize(n);
	rep(i, 0, n-1) {
		int a, b; cin >> a >> b;
		a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
		e.push_back({ a,b });
	}
	int ans = inf;
	rep(rot, 0, 2) {
		if (k % 2) {
			for (P v : e) {
				cnt = 0;
				dfs(v.first, v.second, 0);
				dfs(v.second, v.first, 0);
				ans = min(ans, cnt);
			}
		}
		else {
			rep(i, 0, n) {
				cnt = 0;
				dfs(i, -1, 0);
				ans = min(ans, cnt);
			}
		}
		k--;
	}
	printf("%d", ans);
	return 0;
}
