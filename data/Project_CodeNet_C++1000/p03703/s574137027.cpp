// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2")

#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <chrono>
#include <vector>
#include <map>
#include <random>
#include <set>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <stdio.h>
#include <queue>
#include <bitset>
#include <cstdlib>
#include <deque>
#include <cassert>
#include <stack>
using namespace std;

#define mp make_pair
#define f first
#define se second
#define pb push_back
#define ppb pop_back
#define ll long long
#define ull unsigned long long
#define cntbit(x) __builtin_popcount(x)
#define endl '\n'
#define uset unordered_set
#define umap unordered_map
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define ld long double
#define pll pair<long long, long long>

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

inline void setin(string s) {
	freopen(s.c_str(), "r", stdin);
}

inline void setout(string s) {
	freopen(s.c_str(), "w", stdout);
}

template <typename T> inline T range(T l, T r) {
	return uniform_int_distribution <T>(l, r)(rng);
}

template <typename T> void Min(T &a, T b) {
    a = min(a, b);
}
 
template <typename T> void Max(T &a, T b) {
    a = max(a, b);
}

#define int long long

const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int N = 2e5 + 15;
int n, a[N];
vector <int> is;

struct fenwick {
	int t[N];
	inline void inc(int i, int val) {
		for(; i < is.size(); i = (i | (i + 1)))
			t[i] += val;
	}
	inline int get(int i) {
		int res = 0;
		for(; i >= 0; i = (i & (i + 1)) - 1)
			res += t[i];
		return res;
	}
} t;

inline int gt(int x) {
	return lower_bound(is.begin(), is.end(), x) - is.begin();
}

int p[N], k;

main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	// setin("input.txt");
	cin >> n >> k;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		p[i] = p[i-1] + a[i];
		is.pb(p[i] - k * i);
	}
	is.pb(0);
	sort(is.begin(), is.end());
	is.erase(unique(is.begin(), is.end()), is.end());

	int ans = 0;

	for(int i = 1; i <= n; ++i) {
		t.inc(gt(p[i-1] - k * (i - 1)), 1);
		ans += t.get(gt(p[i] - k * i));
	}
	cout << ans << endl;
	return 0;
}