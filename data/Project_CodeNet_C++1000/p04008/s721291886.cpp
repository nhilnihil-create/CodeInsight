#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
#define pb push_back
using ll = long long;
using ld = long double;

ll ans = 0;
vector<vector<ll>> g;
int n, k;
ll dfs(ll pos, ll par) {
	ll maxi = 0;
	rep(i,g[pos].size()) {
		if(g[pos][i] == par) continue;
		if(g[pos][i] == pos) continue;
		maxi = max(maxi, dfs(g[pos][i], pos) + 1);
	}
	if(maxi == k - 1 && pos != 0 && par != 0) {
		ans++;
		maxi = -1;
	}
	return maxi;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	vector<ll> a(n);
	rep(i,n) cin >> a[i];
	rep(i,n) a[i]--;
	if(a[0] != 0) {
		ans++;
		a[0] = 0;
	}
	g.resize(n);
	rep(i,n) {
		if(i == 0) continue;
		g[a[i]].pb(i);
	}
	dfs(0, -1);
	cout << ans << endl;
	return 0;
}