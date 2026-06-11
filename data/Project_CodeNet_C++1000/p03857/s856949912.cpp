#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>	// upper_bound(A, A+N, num), lower_bound(A, A+N, num)
#include <functional>
#include <string>
#include <sstream>
#include <complex>
#include <vector>		// V[i],  push_back(x), pop_back(), insert(index, x), erase(index), sort(v.begin(), v.end(), greater<int>())
#include <list>			// push_front(x), push_back(x), pop_front(), pop_back(), insert(index, x)
#include <queue>		// push(x), front(), pop()
#include <deque>
#include <stack>		// push(x), top(), pop()
#include <map>			// M[key],  insert(key, val), erase(key), find(key), 
#include <set>			// insert(key), erase(key), find(key)

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

#define PI 3.141592653589793)
#define MOD 1000000007
#define REP(i, n) for(int i = 0; i < n; i++)

map<pair<int, int>, int> mp;
int N, K, L;
int ans[200002];
int par[200001*2];	//親
int rnk[200001*2];	//木の深さ

//n要素で初期化
void init(int n) {
	for (int i = 0; i < n; i++) {
		par[i] = i;
		rnk[i] = 0;
	}
}

//木の根を求める
int find(int x) {
	if (par[x] == x) {
		return x;
	}
	else {
		return par[x] = find(par[x]);
	}
}

//xとyの属する集合を併合
void unite(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;

	if (rnk[x] < rnk[y]) {
		par[x] = y;
	}
	else {
		par[y] = x;
		if (rnk[x] == rnk[y])rnk[x]++;
	}
}

//xとyが同じ集合に属するか否か
bool same(int x, int y) {
	return find(x) == find(y);
}
void solve() {
	cin >> N >> K >> L;
	init(N*2);
	for (int i = 0; i < K; i++) {
		int p, q;
		cin >> p >> q;
		p--, q--;
		unite(p, q);
	}
	
	for (int i = 0; i < L; i++) {
		int r, s;
		cin >> r >> s;
		r--, s--;
		unite(r+N, s+N);
	}
	for (int i = 0; i < N; i++) {
		mp[P(find(i), find(i+N))]++;
	}
	for (int i = 0; i < N; i++) {
		cout << mp[P(find(i), find(i + N))] << (i != N - 1 ? " " : "\n");
	}
}

int main() {
	solve();
	return 0;
}