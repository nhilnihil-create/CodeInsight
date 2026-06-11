#pragma GCC optimize("unroll-loops,Ofast")
#pragma GCC target("avx,sse,sse2,ssse3,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using ld = long double;
const int maxn = 1<<18, mod = 1e9 + 7;
int n, col[maxn];
vector<int> g[maxn], path;
bool dfs(int v, int p = -1) {
	bool ip = v == n;
	for(auto i : g[v]) if(i != p) {
		ip |= dfs(i, v);
	}

	if(ip) path.pb(v);
	return ip;
}
int count(int v, int p = 0) {
	int cnt = 1;
	for(auto i : g[v]) if(i != p && (col[v] == col[i] || col[i] == 0)) {
		if(col[i] ==0) col[i] == col[v];
		cnt += count(i, v);
	}
	return cnt;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for(int f, t, i = 1; i < n; i++) {
		cin >> f >> t;
		g[f].pb(t);
		g[t].pb(f);
	}
	dfs(1);
	reverse(all(path));
	for(int i = 0; i < (path.size()+1)/2; i++) {
		col[path[i]] = 1;
	}
	for(int i = (path.size()+1)/2; i < path.size(); i++) {
		col[path[i]] = 2;
	}
	cout << (count(n) >= count(1) ? "Snuke" : "Fennec") << '\n';
	return 0;
}
