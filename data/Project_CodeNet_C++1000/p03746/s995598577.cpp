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

vector<vector<int>> g;
vector<int> ans,used;
void dfs(int now) {
	ans.push_back(now);
	used[now] = 1;
	rep(i, 0, g[now].size()) {
		int go = g[now][i];
		if (!used[go]) return dfs(go);
	}
	return;
}

int main(){
	int n, m; cin >> n >> m;
	g.resize(n); used.resize(n, 0);
	rep(i, 0, m) {
		int p, q; cin >> p >> q;
		p--; q--;
		g[p].push_back(q);
		g[q].push_back(p);
	}
	dfs(0);
	reverse(ans.begin(), ans.end());
	ans.pop_back();
	dfs(0);
	printf("%d\n", ans.size());
	rep(i, 0, ans.size()) printf("%d ", ans[i]+1);
	return 0;
}
