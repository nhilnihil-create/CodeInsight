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
const int maxn = 1<<17, mod = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, m, q;
vi g[maxn];
vector<array<int, 3>> v;
int vis[maxn][11], col[maxn];
void dfs(int v, int p, int c, int d) {
	if(vis[v][d]++) return;
	if(!col[v]) col[v] = c;
	if(d)
		for(auto &i : g[v]) if(i != p) dfs(i, v, c, d-1);
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	for(int f, t, i = 0; i < m; i++) {
		cin >> f >> t;
		g[f].pb(t);
		g[t].pb(f);
	}
	cin >> q;
	v.resize(q);
	for(auto &i : v) cin >> i[0] >> i[2] >> i[1];
	reverse(all(v));
	for(auto &i : v) {
		dfs(i[0], i[0], i[1], i[2]);
	}
	for(int i = 1; i <= n; i++) cout << col[i] << "\n";
}
