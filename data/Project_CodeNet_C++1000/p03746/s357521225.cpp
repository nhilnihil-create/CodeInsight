#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,popcnt,sse4.1,sse4.2,tune=native")
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
const int maxn = 1<<20, mod = 119<<23|1;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, m;
vi g[maxn];
deque<int> ans;
vi vis;
bool ext(int &v, int a) {
	for(auto u : g[v]) {
		if(!vis[u]) {
			vis[v = u] = 1;
			if(a) ans.push_back(u);
			else ans.push_front(u);
			return true;
		}
	}
	return false;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	vis = vi(n+1, 0);
	for(int f, t, i = 0; i < m; i++) {
		cin >> f >> t;
		g[f].pb(t);
		g[t].pb(f);
	}
	int l = 1, r = g[1][0];
	ans.push_back(l), ans.push_back(r);
	vis[l] = vis[r] = 1;
	while(ext(l, 0) || ext(r, 1));
	cout << ans.size() << '\n';
	for(auto &i : ans) cout << i << " ";
}
