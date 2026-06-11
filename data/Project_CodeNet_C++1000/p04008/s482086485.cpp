#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <utility>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <climits>
#include <numeric>
#include<stdio.h>
#include <queue>
#include <iomanip>
#include <float.h>
#include <set>
#include<functional>
#include <stack>
#include <time.h>
#include <climits>
#include <bitset>
#include <fstream>
#include<map>
#include <cassert>
using namespace std;
long long gcd(long long a, long long b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
vector<long long> divisor(long long n) {
	vector< long long> ret;
	for (long long i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			ret.push_back(i);
			if (i * i != n) ret.push_back(n / i);
		}
	}
	sort(begin(ret), end(ret));
	return (ret);
}
struct LazySegmentTree {
private:
	int n;
	vector<int> node, lazy;
	vector<bool> lazyFlag;

public:
	LazySegmentTree(vector<int> v) {
		int sz = (int)v.size();
		n = 1; while (n < sz) n *= 2;
		node.resize(2 * n - 1);
		lazy.resize(2 * n - 1, INT_MAX);
		lazyFlag.resize(2 * n - 1, false);

		for (int i = 0; i<sz; i++) node[i + n - 1] = v[i];
		for (int i = n - 2; i >= 0; i--) node[i] = min(node[i * 2 + 1], node[i * 2 + 2]);
	}

	void lazyEvaluate(int k, int l, int r) {
		if (lazyFlag[k]) {
			node[k] = lazy[k];
			if (r - l > 1) {
				lazy[k * 2 + 1] = lazy[k * 2 + 2] = lazy[k];
				lazyFlag[k * 2 + 1] = lazyFlag[k * 2 + 2] = true;
			}
			lazyFlag[k] = false;
		}
	}

	void update(int a, int b, int x, int k = 0, int l = 0, int r = -1) {
		if (r < 0) r = n;
		lazyEvaluate(k, l, r);
		if (b <= l || r <= a) return;
		if (a <= l && r <= b) {
			lazy[k] = x;
			lazyFlag[k] = true;
			lazyEvaluate(k, l, r);
		}
		else {
			update(a, b, x, 2 * k + 1, l, (l + r) / 2);
			update(a, b, x, 2 * k + 2, (l + r) / 2, r);
			node[k] = min(node[2 * k + 1], node[2 * k + 2]);
		}
	}

	int find(int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0) r = n;
		lazyEvaluate(k, l, r);
		if (b <= l || r <= a) return INT_MAX;
		if (a <= l && r <= b) return node[k];
		int vl = find(a, b, 2 * k + 1, l, (l + r) / 2);
		int vr = find(a, b, 2 * k + 2, (l + r) / 2, r);
		return min(vl, vr);
	}
};
#define ll long long
class UnionFind {
public:
	vector <ll> par; // 各元の親を表す配列
	vector <ll> siz; // 素集合のサイズを表す配列(1 で初期化)

					 // Constructor
	UnionFind(ll sz_) : par(sz_), siz(sz_, 1LL) {
		for (ll i = 0; i < sz_; ++i) par[i] = i; // 初期では親は自分自身
	}
	void init(ll sz_) {
		par.resize(sz_);
		siz.assign(sz_, 1LL);  // resize だとなぜか初期化されなかった
		for (ll i = 0; i < sz_; ++i) par[i] = i; // 初期では親は自分自身
	}

	// Member Function
	// Find
	ll root(ll x) { // 根の検索
		while (par[x] != x) {
			x = par[x] = par[par[x]]; // x の親の親を x の親とする
		}
		return x;
	}

	// Union(Unite, Merge)
	bool merge(ll x, ll y) {
		x = root(x);
		y = root(y);
		if (x == y) return false;
		// merge technique（データ構造をマージするテク．小を大にくっつける）
		if (siz[x] < siz[y]) swap(x, y);
		siz[x] += siz[y];
		par[y] = x;
		return true;
	}

	bool issame(ll x, ll y) { // 連結判定
		return root(x) == root(y);
	}

	ll size(ll x) { // 素集合のサイズ
		return siz[root(x)];
	}
};
struct segtree {
	int N, dat[2 * 1000004];
	segtree() {}
	segtree(int n) {
		N = 1;
		while (N < n) N *= 2;
		for (int i = 0; i < 2 * N - 1; i++)
			dat[i] = INT_MIN;
	}
	// update k th element
	void update(int k, int a) {
		k += N - 1; // leaf
		dat[k] = a;
		while (k > 0) {
			k = (k - 1) / 2;
			dat[k] = max(dat[k * 2 + 1], dat[k * 2 + 2]);
		}
	}
	// min [a, b)
	int query(int a, int b) { return query(a, b, 0, 0, N); }
	int query(int a, int b, int k, int l, int r) {
		if (r <= a || b <= l) return INT_MIN;
		if (a <= l && r <= b) return dat[k];
		int m = (l + r) / 2;
		return max(query(a, b, k * 2 + 1, l, m), query(a, b, k * 2 + 2, m, r));
	}
};
typedef pair<int,int>p;
long long mod = 1e9 + 7;
vector<int>child[100004];
int parent[100004];
int ans = 0;
int n, k;
int dfs(int now) {
	int maxi = 0;
	for (int i = 0; i < child[now].size(); i++) {
		int to = child[now][i];
		maxi = max(maxi, dfs(to)+1);
	}
	if (maxi == k - 1 && parent[now] != 1) {
		ans += 1;
		maxi = -1;
	}
	return maxi;
}
signed main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(16);
	cin >> n >> k;
	int tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		if (i == 0) {
			if (tmp != 1)ans += 1;
			parent[1] = 1;
		}
		else {
			child[tmp].push_back(i + 1);
			parent[i + 1] = tmp;
		}
	}
	dfs(1);
	cout << ans;
}