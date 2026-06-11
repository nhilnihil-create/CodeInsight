#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<int>;
const int maxn = 62, mlg = 18, rt = 1<<10, mod = 1e9 + 7;
struct dsu {
	vi p, r;
	vector<vi> col;
	dsu(int n) {
		p.resize(n+1);
		iota(all(p), 0);
		r.resize(n+1,1);
		col.resize(n+1);
	}
	int par(int v) {
		return v^p[v] ? p[v] = par(p[v]) : v;
	}
	void unite(int i, int j) {
		i = par(i), j = par(j);
		if(i == j) return;
		if(r[i] < r[j]) swap(i, j);
		p[j] = i, r[i] += r[j];
		for(auto x : col[j]) col[i].push_back(x);
	}
};
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, k, l;
	cin >> n >> k >> l;
	dsu a(n), b(n);
	int f, t;
	while(k--) {
		cin >> f >> t;
		a.unite(f, t);
	}
	for(int i = 1; i <= n; i++) b.col[i].pb(a.par(i));
	while(l--) {
		cin >> f >> t;
		b.unite(f, t);
	}
	vector<map<int, int>> ans(n+1);
	for(int i = 1; i <= n; i++) if(i == b.par(i)) {
		for(auto j : b.col[i]) ans[j][i]++;
	}
	for(int i = 1; i <= n; i++) {
		f = a.par(i), t = b.par(i);
		cout << ans[f][t] << ' ';
	}
} 
