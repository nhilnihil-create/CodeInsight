#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <cstring>

using namespace std;
// ascending order
#define vsort(v) sort(v.begin(), v.end())
// descending order
#define vsort_r(v) sort(v.begin(), v.end(), greater<int>())
#define vunique(v) unique(v.begin(), v.end())
#define mp make_pair
#define ts(x) to_string(x)
#define rep(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define repm(i, a, b) for(int i = (int)a; i > (int)b; i--)
#define bit(a) bitset<8>(a)
#define des_priority_queue priority_queue<int, vector<int>, greater<int> >
typedef long long ll;
typedef pair<int, int> P;
const ll INF = 1e18;
const int MAX_N = 2 * 1e5;

struct UnionFind {

	int par[MAX_N]; // 親
	int depth[MAX_N]; // 木の深さ

	// n要素で初期化
	void init(int n) {
		rep(i, 0, n) {
			par[i] = i;
			depth[i] = 0;
		}
	}

	// 木の根を求める
	int find(int x) {
		if(par[x] == x) return x;
		else return par[x] = find(par[x]);
	}

	// xとyの属する集合を併合
	void unite(int x, int y) {
		x = find(x);
		y = find(y);
		if(x == y) return;

		if(depth[x] < depth[y]) {
			par[x] = y;
		} else {
			par[y] = x;
			if(depth[x] == depth[y]) depth[x]++;
		}
	}

	// xとyが同じ集合に属するか否か
	bool same(int x, int y) {
		return find(x) == find(y);
	}
};

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	UnionFind uf1, uf2;

	int N, K, L;
	cin >> N >> K >> L;
	uf1.init(N); uf2.init(N);

	rep(i, 0, K) {
		int p, q;
		cin >> p >> q;
		p--; q--;
		uf1.unite(p, q);
	}

	rep(i, 0, L) {
		int r, s;
		cin >> r >> s;
		r--; s--;
		uf2.unite(r, s);
	}

	vector<pair<int, int> > vp(N);
	map<pair<int, int>, int> mp;
	rep(i, 0, N) {
		vp[i].first = uf1.find(i);
		vp[i].second = uf2.find(i);
		mp[vp[i]]++;
	}

	rep(i, 0, N - 1) cout << mp[vp[i]] << " ";
	cout << mp[vp[N - 1]] << endl;



}
