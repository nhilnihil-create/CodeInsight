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

const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int N = 1e5 + 15;
const int L = 21;
int n, a[N], b[N], l, q;
int p[N], up[L][N], d[N];

deque <int> cur;

vector <int> g[N];

inline void precalc() {
	for(int i = 1; i <= n; ++i) {
		while(!cur.empty() && a[cur.front()] + l < a[i])
			cur.pop_front();
		if(!cur.empty())
			p[i] = cur.front();
		if(p[i])
			g[p[i]].pb(i);
		cur.pb(i);
	}
}

void dfs(int v, int p) {
	up[0][v] = p;
	for(int i = 1; i < L; ++i)
		up[i][v] = up[i-1][up[i-1][v]];
	for(int to : g[v])
		if(to != p) {
			d[to] = d[v] + 1;
			dfs(to, v);
		}
}

inline int get(int v, int x) {
	for(int i = L - 1; i >= 0; --i)
		if(up[i][v] > x)
			v = up[i][v];
	return v;
}

main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	// setin("input.txt");
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	cin >> l;
	precalc();
	dfs(1, 1);
	// for(int i = 1; i <= n; ++i)
	// 	cout << d[i] << ' ';
	// cout << endl;

	cin >> q;
	while(q--){ 
		int a, b;
		cin >> a >> b;
		if(a > b)
			swap(a, b);
		int v = get(b, a);
		cout << d[b] - d[v] + 1 << endl;
	}
	return 0;
}