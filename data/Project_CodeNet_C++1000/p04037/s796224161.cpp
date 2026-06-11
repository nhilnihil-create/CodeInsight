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
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> P;
typedef complex<ld> com;
constexpr int inf = 1000000000;
constexpr ll INF = 1000000000000000010;
constexpr ld EPS = 1e-12;
constexpr ld PI = 3.141592653589793238;
template<class T, class U> inline bool chmax(T &a, const U &b) { if (a < b) { a = b; return true; } return false; }
template<class T, class U> inline bool chmin(T &a, const U &b) { if (a > b) { a = b; return true; } return false; }


signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(20);

	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	sort(all(a));
	vector<bool> ans(n*10); int idx = 0;
	rep(i, n) {
		if (idx >= n) break;
		if (i > 0 && a[i] == a[i - 1]) {
			ans[idx] = !ans[idx - 1];
			idx++;
			continue;
		}
		int cnt = min((i ? a[i] - a[i - 1] + 1 : a[i]), n - idx);
		int tp = cnt + (i ? a[i - 1] : 1) - 1;
		if ((a[i] - tp) % 2 != 0) ans[idx + cnt - 1] = true;
		for (int j = idx + cnt - 2; j >= idx; j--) ans[j] = !ans[j + 1];
		if (idx && !ans[idx - 1]) ans[idx] = true;
		idx += cnt;
	}
	cout << (ans[n - 1] ? "First" : "Second") << '\n';
}