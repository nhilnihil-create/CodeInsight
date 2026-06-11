#include <bits/stdc++.h>

using namespace std;

#define REP(i,n) for(int i=0; i<int(n); i++)
#define FOR(i,m,n) for(int i=int(m); i<int(n); i++)
#define ALL(obj) (obj).begin(),(obj).end()
#define VI vector<int>
#define VLL vector<long long>
#define VVI vector<vector<int>>
#define VVLL vector<vector<long long>>
#define VC vector<char>
#define VS vector<string>
#define VVS vector<vector<string>>
#define VVC vector<vector<char>>
#define fore(i,a) for(auto &i:a)
typedef long long ll;
typedef pair <int, int> P;
const int  INF = 2147483647;
const ll INFL = 9223372036854775807;
const ll mod = 1000000007;

struct UnionFind {
	vector<int> par;
	int cnt;
	UnionFind(int size_) : par(size_, -1), cnt(size_) { }
	bool unite(int x, int y) {
		x = find(x); y = find(y);
		if (x != y) {
			if (par[y] < par[x]) swap(x, y);
			par[x] += par[y]; par[y] = x;
			cnt--;
		}
		return x != y;
	}
	bool same(int x, int y) {
		return find(x) == find(y);
	}
	int find(int x) {
		return par[x] < 0 ? x : par[x] = find(par[x]);
	}
	int size(int x) {
		return -par[find(x)];
	}
	int size() {
		return cnt;
	}
};


int main() {
	int n, k, l;
	cin >> n >> k >> l;
	UnionFind ufk(n + 2), ufl(n + 2);
	REP(i, k) {
		int a, b;
		cin >> a >> b;
		ufk.unite(a, b);
	}
	REP(i, l) {
		int a, b;
		cin >> a >> b;
		ufl.unite(a, b);
	}
	vector<pair<int, int>> v;
	FOR(i,1, n + 1)v.push_back({ ufk.find(i),ufl.find(i) });
	sort(ALL(v));
	FOR(i, 1, n+1) {
		pair<int, int> p(ufk.find(i), ufl.find(i));
		cout << upper_bound(ALL(v), p) - lower_bound(ALL(v), p);
		if (i != n)cout << ' ';
		else cout << endl;
	}
	return 0;

}
