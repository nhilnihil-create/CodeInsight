#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <utility>
#include <tuple>
#include <functional>
#include <bitset>
#include <cassert>
#include <complex>
#include <stdio.h>
#include <time.h>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#define all(a) a.begin(),a.end()
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define pb push_back
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;
typedef complex<ld> com;
constexpr int inf = 1000000000;
constexpr ll INF = 1000000000000000000;
constexpr ld EPS = 1e-12;
constexpr ld PI = 3.141592653589793238;
template<class T, class U> inline bool chmax(T &a, const U &b) { if (a < b) { a = b; return true; } return false; }
template<class T, class U> inline bool chmin(T &a, const U &b) { if (a > b) { a = b; return true; } return false; }


signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(20);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> dis(n, vector<int>(n, inf));
	vector<int> a(m), b(m), c(m);
	rep(i, m) {
		cin >> a[i] >> b[i] >> c[i];
		a[i]--; b[i]--;
		dis[a[i]][b[i]] = c[i];
		dis[b[i]][a[i]] = c[i];
	}
	rep(k, n) {
		rep(i, n) {
			rep(j, n) {
				chmin(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	int ans = m;
	rep(i, m) {
		if (dis[a[i]][b[i]] == c[i]) ans--;
	}
	cout << ans << '\n';
}