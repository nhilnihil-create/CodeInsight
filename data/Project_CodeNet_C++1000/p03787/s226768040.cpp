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
int n,m,qsz = 0;
vi g[maxn];
vi q[maxn];
int vis[maxn];
vi st;
int bip, csz;

void dfs(int v, int c = 1) {
	csz++;
	vis[v] = c;
	for(auto &i : g[v]) {
		if(c == vis[i]) bip = 0;
		if(!vis[i]) dfs(i, c^3);
	}
}

ll count() {
	ll i, b, u;
	i = b = u = 0;
	for(int v = 1; v <= n; v++) {
		if(vis[v]) continue;
		bip = 1, csz = 0;
		dfs(v);
		if(csz == 1) i++;
		else if(bip) b++;
		else u++;
	}
	return i * 2 * n - i*i + 2*b*(b+u) + u*u;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	for(int f, t, i = 0; i < m; i++) {
		cin >> f >> t;
		g[f].pb(t);
		g[t].pb(f);
	}
	cout << count();
}
