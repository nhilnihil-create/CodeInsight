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

const ll inf = 2e15;
const int mod = 1e9 + 7;
const int N = 1e5 + 15;
int n, a[N], c[N];
vector <int> g[N];

inline void no() {
	cout << "NO" << endl;
	exit(0);
}

void dfs(int v, int p = -1) {
	int sum = 0;
	for(int to : g[v])
		if(to != p) {
			dfs(to, v);
			sum += c[to];
		}
	if(p != -1) {
		c[v] = (g[v].size() == 1 ? a[v] : 2 * a[v]) - sum;
	}
	else {

		if(g[v].size() == 1) {
			if(sum != a[v])
				no();
		}
		else if(sum != 2 * a[v])
			no();
	}
	if(c[v] < 0)
		no();
	for(int to : g[v])
		if(g[v].size() != 1 && ((to != p && c[to] > a[v]) || c[v] > a[v]))
			no();
}

main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	// setin("input.txt");
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(1);
	cout << "YES" << endl;
	return 0;
}
