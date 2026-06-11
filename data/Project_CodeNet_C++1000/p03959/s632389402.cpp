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
#define debug(x) cerr << __LINE__ << ' ' << #x << ':' << x << '\n'
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


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(20);

	int n;
	cin >> n;
	vector<P> ans(n);
	vector<int> a(n), b(n);
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> b[i];
	rep(i, n) {
		int pre = 0;
		if (i) pre = a[i - 1];
		if (pre != a[i]) {
			ans[i].first = a[i];
			ans[i].second = 1;
		}
		else {
			ans[i].first = a[i];
			ans[i].second = 0;
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		int pre = 0;
		if (i != n - 1) pre = b[i + 1];
		if (pre != b[i]) {
			if (ans[i].second == 1) {
				if (ans[i].first != b[i]) {
					cout << "0\n";
					return 0;
				}
			}
			else {
				if (ans[i].first < b[i]) {
					cout << "0\n";
					return 0;
				}
				ans[i].second = 1;
			}
		}
		else {
			if (ans[i].second == 1) {
				if (ans[i].first > b[i]) {
					cout << "0\n";
					return 0;
				}
			}
			else {
				chmin(ans[i].first, b[i]);
			}
		}
	}
	ll res = 1;
	for (P i : ans) {
		if (i.second == 0) {
			res *= i.first;
			res %= 1000000007;
		}
	}
	cout << res << '\n';
}