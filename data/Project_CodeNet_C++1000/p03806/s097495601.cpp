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

int dp[50][500][500];

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(20);

	int n, ma, mb;
	cin >> n >> ma >> mb;
	vector<int> a(n), b(n), c(n);
	rep(i, n) cin >> a[i] >> b[i] >> c[i];
	rep(i, n + 1) rep(j, 500) rep(k, 500) dp[i][j][k] = inf;
	dp[0][0][0] = 0;
	rep(i, n) {
		rep(j, 500) {
			rep(k, 500) {
				chmin(dp[i + 1][j][k], dp[i][j][k]);
				if (j >= a[i] && k >= b[i]) chmin(dp[i + 1][j][k], dp[i][j - a[i]][k - b[i]] + c[i]);
			}
		}
	}
	int ans = inf;
	rep(j, 500) {
		rep(k, 500) {
			if (j == 0 || k == 0) continue;
			if (j * mb == k * ma) chmin(ans, dp[n][j][k]);
		}
	}
	cout << (ans == inf ? -1 : ans) << '\n';
}