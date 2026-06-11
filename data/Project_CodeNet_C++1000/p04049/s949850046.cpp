#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
#define fi first
#define se second

vector<int> g[100005];
int n, k, ans = LONG_MAX;

vector<pair<int,int> > e;

int dfs(int u,int p,int dep){
	if(dep == 0) return 1;
	int res = 1;
	for(int v: g[u]) if(v != p)
		res += dfs(v, u, dep - 1);
	return res;
}

signed main(){
	cin >> n >> k;
	for(int i = 1 ; i < n ; i ++){
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
		e.push_back({u, v});
	}

	for(pair<int,int> p: e){
		ans = min(ans, n - dfs(p.fi, p.se, k / 2) - dfs(p.se, p.fi, (k / 2) - (k % 2 == 0)));
		ans = min(ans, n - dfs(p.se, p.fi, k / 2) - dfs(p.fi, p.se, (k / 2) - (k % 2 == 0)));
	}
	cout << ans;
}
