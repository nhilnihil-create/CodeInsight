#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,x,n) for(int i=x;i<n;i++)
#define ALL(v) (v).begin(),(v).end()
#define MP(a,b) make_pair(a,b)
typedef long long LL;
typedef pair<int, int> PI;
typedef vector<int> VI;
const LL MOD = 1000000007LL;
struct UnionFind {
	int *par;
	int *rank;
	UnionFind(int n) {
		par = new int[n];
		rank = new int[n];
		for (int i = 0; i < n; i++) {
			par[i] = i;
			rank[i] = 0;
		}
	}
	int find(int x) {
		if (par[x] == x) {
			return x;
		}
		else {
			return par[x] = find(par[x]);
		}
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
	bool same(int x, int y) {
		return find(x) == find(y);
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
	map<PI, int> cnt;
	rep(i, N) {
		cnt[MP(road.find(i), rail.find(i))]++;
	}
	rep(i, N) {
		cout << cnt[MP(road.find(i), rail.find(i))] << " ";
	}
	cout << endl;
}