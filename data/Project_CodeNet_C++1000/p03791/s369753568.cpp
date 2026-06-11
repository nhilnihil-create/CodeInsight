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
#include <random>
#include <unordered_map>
#include <unordered_set>
#define all(a) a.begin(),a.end()
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define pb push_back
#define debug(x) cerr << #x << ':' << (x) << '\n'
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> P;
typedef complex<ld> com;
constexpr int inf = 1000000010;
constexpr ll INF = 1000000000000000010;
constexpr ld eps = 1e-12;
constexpr ld pi = 3.141592653589793238;
template<class T, class U> inline bool chmax(T &a, const U &b) { if (a < b) { a = b; return true; } return false; }
template<class T, class U> inline bool chmin(T &a, const U &b) { if (a > b) { a = b; return true; } return false; }

constexpr ll mod = 1000000007;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(20);

	int n;
	cin >> n;
	vector<int> x(n);
	rep(i, n) cin >> x[i];
	vector<int> ok(n);
	ok[0] = 1;
	rep(i, n - 1) {
		ok[i + 1] = ok[i];
		ll d = 2 * i + 4 - x[i];
		chmax(ok[i + 1], d / 2);
	}
	vector<int> cnt(n + 1);
	rep(i, n) cnt[ok[i]]++;
	ll ans = 1; ll s = 0;
	for (int i = 1; i <= n; i++) {
		s += cnt[i];
		ans *= s; ans %= mod;
		s--;
	}
	cout << ans << '\n';
}