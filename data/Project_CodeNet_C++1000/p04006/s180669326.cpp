#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>
#include <stack>
#include <functional>

#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; ++i)
#define repp(i, m, n) for(ll i = m, i##_len = (n); i < i##_len; ++i)
#define reprev(i, n) for(ll i = (n-1LL); i >= 0; --i)
#define all(x) (x).begin(), (x).end()
template <class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template <class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }
template <class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int,int> P;
typedef long double ld;

template< typename Monoid >
struct SegmentTree {
	using F = function< Monoid(Monoid, Monoid) >;
	int sz;
	vector< Monoid > seg;
	const F f;
	const Monoid M1;
	SegmentTree(int n, const F f, const Monoid &M1) : f(f), M1(M1) {
		sz = 1;
		while(sz < n) sz <<= 1;
		seg.assign(2 * sz, M1);
	}
	void set(int k, const Monoid &x) {
		seg[k + sz] = x;
	}
	void build() {
		for(int k = sz - 1; k > 0; k--) {
			seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
		}
	}
	void update(int k, const Monoid &x) {
		k += sz;
		seg[k] = x;
		while(k >>= 1) {
			seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
		}
	}
	Monoid query(int a, int b) {
		Monoid L = M1, R = M1;
		for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
			if(a & 1) L = f(L, seg[a++]);
			if(b & 1) R = f(seg[--b], R);
		}
		return f(L, R);
	}
	Monoid operator[](const int &k) const {
		return seg[k + sz];
	}
	template< typename C >
	int find_subtree(int a, const C &check, Monoid &M, bool type) {
		while(a < sz) {
			Monoid nxt = type ? f(seg[2 * a + type], M) : f(M, seg[2 * a + type]);
			if(check(nxt)) a = 2 * a + type;
			else M = nxt, a = 2 * a + 1 - type;
		}
		return a - sz;
	}
	template< typename C >
	int find_first(int a, const C &check) {
		Monoid L = M1;
		if(a <= 0) {
			if(check(f(L, seg[1]))) return find_subtree(1, check, L, false);
			return -1;
		}
		int b = sz;
		for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
			if(a & 1) {
				Monoid nxt = f(L, seg[a]);
				if(check(nxt)) return find_subtree(a, check, L, false);
				L = nxt;
				++a;
			}
		}
		return -1;
	}
	template< typename C >
	int find_last(int b, const C &check) {
		Monoid R = M1;
		if(b >= sz) {
			if(check(f(seg[1], R))) return find_subtree(1, check, R, true);
			return -1;
		}
		int a = sz;
		for(b += sz; a < b; a >>= 1, b >>= 1) {
			if(b & 1) {
				Monoid nxt = f(seg[--b], R);
				if(check(nxt)) return find_subtree(b, check, R, true);
				R = nxt;
			}
		}
		return -1;
	}
};

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, x;
	cin >> n >> x;
	SegmentTree<int> st(n, [](int a, int b) {return min(a, b);}, INT32_MAX);
	ll ans = 10000000000000000LL;
	rep (i, n) {
		int a;
		cin >> a;
		st.update(i, a);
	}
	rep (i, n) { // number of x
		ll tmp = 0;
		rep (j, n) {
			if (j - i < 0) {
				tmp += min(st.query(0, j + 1), st.query((j - i) % n + n, n));
			} else {
				tmp += st.query(j - i, j + 1);
			}
		}
		tmp += i * x;
		chmin(ans, tmp);
	}
	cout << ans << "\n";
	return 0;
}