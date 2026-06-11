#pragma GCC optimize("trapv")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
//using arr = array;
using pi = pair<int, int>;
using vi = vector<ll>;
using vvi = vector<vi>;
using vpi = vector<pi>;
using ld = long double;
const int maxn = 1<<18, mod = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, a[maxn];
vi g[maxn];
ll dfs(ll v, ll p) {
	ll sm = 0, m = 0;
	for(auto &i : g[v]) {
		if(i == p) continue;
		ll t =  dfs(i, v);
		sm += t;
		m = max(m, t); 
	}
	if(g[v].size() == 1) return a[v];
	ll x = sm - a[v];
	if(x < 0 || x > sm-m || sm - 2*x < 0) {cout << "NO", exit(0);}
	return sm - 2*x;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int f, t, i = 1; i < n; i++) {
		cin >> f >> t;
		g[f].pb(t);
		g[t].pb(f);
	}
	if(n == 2) return cout << (a[1] == a[2] ? "YES" : "NO"), 0;
	int r = 1;
	while(g[r].size()<2) r++;
	cout << (dfs(r, r) ? "NO" : "YES");
}
