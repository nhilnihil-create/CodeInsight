#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <functional>
#include <cmath>
#include <complex>
#include <cctype>
#include <cassert>
#include <sstream>
#include <ctime>
 
using namespace std;
 
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
 
template<typename A, typename B> inline bool chmax(A &a, B b) { if (a<b) { a=b; return 1; } return 0; }
template<typename A, typename B> inline bool chmin(A &a, B b) { if (a>b) { a=b; return 1; } return 0; }
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pii, int> P;
 
#define INF (1<<29)
#define INFL (1ll<<60)
#define EPS (1e-8)
#define PI (acos(-1))
const ll MOD = 1000000007ll;

struct UnionFind {
	vector<int> par;
	vector<int> rank;
	
	UnionFind() {}
	UnionFind(int n) {
		init(n);
	}
	
	int operator[] (int x) {
		return find(x);
	}

	void init(int n) {
		par.resize(n);
		rank.resize(n);
		REP(i, n) {
			par[i] = i;
			rank[i] = 0;
		}
	}

	int find(int x) {
		if (par[x] == x) return x;
		return par[x] = find(par[x]);
	}

	void unite(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y) return;

		if (rank[x] < rank[y]) {
			par[x] = y;
		} else {
			par[y] = x;
			if (rank[x] == rank[y]) rank[x]++;
		}
	}

	bool same(int x, int y) {
		return find(x) == find(y);
	}
};

int n, m;
vector<int> g[112345];


int color[112345];

bool binary_color(int v,int c) {
	color[v] = c;
	
	REP(i, g[v].size()) {
		int u = g[v][i];
		
		if (color[u] == 0) {
			if (!binary_color(u, -c)) return false;
		}
		else {
			if (color[u] == c) return false;
		}
	}
	
	return true;
}

int main() {
	cin >> n >> m;
	
	UnionFind uf(n);
	
	REP(i, m) {
		int u, v;
		scanf("%d %d", &u, &v);
		u--; v--;
		g[u].push_back(v);
		g[v].push_back(u);
		
		uf.unite(u, v);
	}
	
	ll isc = 0; // 孤立点
	ll bpc = 0; // 二部グラフ
	ll odc = 0; // not二部グラフ
	
	map<int, int> m;
	REP(i, n) m[uf[i]]++;
	
	bool done[112345] = {};
	REP(i, n) {
		if (done[uf[i]]) continue;
		done[uf[i]] = true;
		
		if (m[uf[i]] == 1) isc++;
		else {
			fill(color, color + n, 0);
			if (binary_color(i, 1)) bpc++;
			else odc++;
		}
	}
	
	ll ans = 2*bpc*bpc + isc*isc + odc*odc + 2 * (bpc * odc + isc * (n - isc));
	
	cout << ans << endl;
	
	return 0;
}