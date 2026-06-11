#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
#define ALL(v) (v).begin(),(v).end()
typedef long long LL;
const int INF = 1 << 25;
const LL MOD = 1000000007LL;
using namespace std;
typedef pair<int, int> P;
struct UnionFind {
	int *par;
	int *rank;
	UnionFind(int n) {
		par = new int[n];
		rank = new int[n];
		rep(i, n) {
			par[i] = i;
			rank[i] = 0;
		}
	}
	int find(int x) {
		if (x == par[x]) return x;
		return par[x] = find(par[x]);
	}
	bool same(int x, int y) {
		return find(x) == find(y);
	}
	void unite(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y) return;
		if (rank[x] < rank[y]) {
			par[x] = y;
		}
		else {
			par[y] = x;
			if (rank[x] == rank[y]) rank[x]++;
		}
	}
};
int main() {
	int N, K, L;
	cin >> N >> K >> L;
	UnionFind road(N), rail(N);
	rep(i, K) {
		int p, q;
		cin >> p >> q;
		p--; q--;
		road.unite(p, q);
	}
	rep(i, L) {
		int r, s;
		cin >> r >> s;
		r--; s--;
		rail.unite(r, s);
	}
	map<P, int> cnt;
	rep(i, N) {
		cnt[P(road.find(i), rail.find(i))]++;
	}
	rep(i, N) {
		if (i > 0) cout << " ";
		cout << cnt[P(road.find(i), rail.find(i))];
	}
	cout << endl;
}