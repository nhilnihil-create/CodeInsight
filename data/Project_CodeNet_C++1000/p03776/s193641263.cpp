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

ll comb[52][52];

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(20);

	int n, a, b;
	cin >> n >> a >> b;
	vector<ll> v(n);
	rep(i, n) cin >> v[i];
	sort(all(v)); reverse(all(v));
	ll sum = 0;
	rep(i, a) sum += v[i];
	cout << (double)sum / a << '\n';
	int cnt = 0;
	rep(i, n) if (v[i] == v[a - 1]) cnt++;
	int use = 0;
	rep(i, a) if (v[i] > v[a - 1]) use++;
	comb[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		rep(j, i + 1) {
			comb[i][j] += comb[i - 1][j];
			if (j != 0) comb[i][j] += comb[i - 1][j - 1];
		}
	}
	ll ans = comb[cnt][a - use];
	if (sum == v[a - 1] * a) for (int i = a - use + 1; i <= b - use; i++) ans += comb[cnt][i];
	cout << ans << '\n';
}