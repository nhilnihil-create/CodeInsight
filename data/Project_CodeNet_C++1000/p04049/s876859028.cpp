/* ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄▄            ▄            ▄▄▄▄▄▄▄▄▄▄▄  ▄         ▄       ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄
▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░▌          ▐░▌          ▐░░░░░░░░░░░▌▐░▌       ▐░▌     ▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░▌
▐░█▀▀▀▀▀▀▀▀▀ ▐░█▀▀▀▀▀▀▀█░▌▐░▌          ▐░▌          ▐░█▀▀▀▀▀▀▀█░▌▐░▌       ▐░▌     ▐░█▀▀▀▀▀▀▀▀▀ ▐░█▀▀▀▀▀▀▀█░▌▐░█▀▀▀▀▀▀▀█░▌
▐░▌          ▐░▌       ▐░▌▐░▌          ▐░▌          ▐░▌       ▐░▌▐░▌       ▐░▌     ▐░▌          ▐░▌       ▐░▌▐░▌       ▐░▌
▐░█▄▄▄▄▄▄▄▄▄ ▐░▌       ▐░▌▐░▌          ▐░▌          ▐░▌       ▐░▌▐░▌   ▄   ▐░▌     ▐░▌ ▄▄▄▄▄▄▄▄ ▐░▌       ▐░▌▐░▌       ▐░▌
▐░░░░░░░░░░░▌▐░▌       ▐░▌▐░▌          ▐░▌          ▐░▌       ▐░▌▐░▌  ▐░▌  ▐░▌     ▐░▌▐░░░░░░░░▌▐░▌       ▐░▌▐░▌       ▐░▌
▐░█▀▀▀▀▀▀▀▀▀ ▐░▌       ▐░▌▐░▌          ▐░▌          ▐░▌       ▐░▌▐░▌ ▐░▌░▌ ▐░▌     ▐░▌ ▀▀▀▀▀▀█░▌▐░▌       ▐░▌▐░▌       ▐░▌
▐░▌          ▐░▌       ▐░▌▐░▌          ▐░▌          ▐░▌       ▐░▌▐░▌▐░▌ ▐░▌▐░▌     ▐░▌       ▐░▌▐░▌       ▐░▌▐░▌       ▐░▌
▐░▌          ▐░█▄▄▄▄▄▄▄█░▌▐░█▄▄▄▄▄▄▄▄▄ ▐░█▄▄▄▄▄▄▄▄▄ ▐░█▄▄▄▄▄▄▄█░▌▐░▌░▌   ▐░▐░▌     ▐░█▄▄▄▄▄▄▄█░▌▐░█▄▄▄▄▄▄▄█░▌▐░█▄▄▄▄▄▄▄█░▌
▐░▌          ▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░▌     ▐░░▌     ▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░▌
 ▀            ▀▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀▀▀  ▀▀       ▀▀       ▀▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀▀  */

//#pragma optimization_level 3

//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <chrono>
#include <ctime>
#include <queue>
#include <math.h>
#include <deque>
#include <stack>
#include <iomanip>
#include <assert.h>
#include <stdio.h>
#include <cstring>
#include <random>

using namespace std;

#define int long long
#define ld long double
#define ull unsigned long long
#define endl '\n'
#define try tr
#define pii pair<int, int>
#define ti tuple <int, int, int>
#define vi vector <int>
#define vpi vector <pii>
#define umap unordered_map
#define uset unordered_set
#define left left11
#define right right11
#define all(c) (c).begin(), (c).end()
#define pb push_back
#define sqr(a) ((a) * (a))
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define X first
#define Y second

ld TL = 1.0;
bool is_tl = 0;
int CALLS = 0;

inline bool IS() {
    if (++CALLS == 1000) {
        CALLS = 0;
        is_tl |= clock() > (TL - 0.1) * CLOCKS_PER_SEC;
    }
    return is_tl;
}

template<typename T1, typename T2>
inline void amin(T1 &a, T2 b) { if (a > b) a = b; }

template<typename T1, typename T2>
inline void amax(T1 &a, T2 b) { if (a < b) a = b; }

template<typename T1, typename T2>
ostream &operator<<(ostream &os, pair<T1, T2> &p) {
    os << p.first << ' ' << p.second << endl;
    return os;
}

template<typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &p) {
    is >> p.first >> p.second;
    return is;
}

template<typename T>
ostream &operator<<(ostream &os, vector<T> &v) {
    for (auto &u : v) os << u << ' ';
    os << endl;
    return os;
}

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 1e6 + 7, NS = 2e3 + 7, lg = 19, sq = 550, inf = 2e9 + 7, SM = 1e2 + 7;
const ld eps = 1e-9;
int hash_mod[4] = {1000000007, 998244353, 1000000009, 999999937}, mod = hash_mod[rnd() % 4];
int hash_pows[4] = {179, 239, 1007, 2003}, P = hash_pows[rnd() % 4];
vi v[N];
vpi edges;
int n, k, cnt = 0, ans = inf;
int dist[N];
void dfs1(int x, int p, int d) {
	if(d > k / 2)
		cnt++;
	for (auto u :v[x]) {
		if(u != p)
			dfs1(u, x, d + 1);
	}
}
void dfs2(int x, int p, int d) {
	dist[x] = min(dist[x], d);
	for (auto u : v[x]) {
		if(u != p)
			dfs2(u, x, d + 1);
	}
}
void solve() {
	cin >> n >> k;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		v[a].pb(b);
		v[b].pb(a);
		edges.pb({a, b});
	}
	if(k % 2 == 0) {
		for (int i = 0; i < n; i++) {
			cnt = 0;
			dfs1(i, -1, 0);
			amin(ans, cnt);
		}
		cout << ans;
		return;
	}
	else {
		for (auto e : edges) {
			fill(dist, dist + n, inf);
			dfs2(e.first, -1, 0);
			dfs2(e.second, -1, 0);
			cnt = 0;
			for (int i = 0; i < n; i++) {
				cnt += (dist[i] > k / 2);
			}
			amin(ans, cnt);
		}
		cout << ans;
	}
}

signed main() {
    fast
    solve();
}