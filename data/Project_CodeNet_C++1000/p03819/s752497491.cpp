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
#define all(a) a.begin(),a.end()
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;
typedef complex<ld> com;
constexpr ll INF = 1000000000000000000;
constexpr ld EPS = 1e-12;
constexpr ld PI = 3.141592653589793238;
template<class T, class U> inline bool chmax(T &a, const U &b) { if (a < b) { a = b; return true; } return false; }
template<class T, class U> inline bool chmin(T &a, const U &b) { if (a > b) { a = b; return true; } return false; }

template<class T> class segtree {
	int n;
	vector<T> data;
	T id;
	function<T(T, T)> operation;
	function<T(T, T)> update;
public:
	segtree(size_t _n, T _id, function<T(T, T)> _operation, function<T(T, T)> _update)
		:id(_id), operation(_operation), update(_update) {
		n = 1;
		while (n < _n + 2) {
			n *= 2;
		}
		data = vector<T>(2 * n, id);
	}
	void change(int a, int b, int x) {
		a += n; b += n;
		while (a < b) {
			if (a & 1) data[a++] = update(data[a], x);
			if (b & 1) data[b] = update(data[--b], x);
			a >>= 1; b >>= 1;
		}
	}
	T get(int i) {
		T ret = id;
		i += n;
		while (i > 0) {
			ret = operation(ret, data[i]);
			i >>= 1;
		}
		return ret;
	}
	//T operator[](int i) { return data[i + n]; }
};

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(20);

	int n, m;
	cin >> n >> m;
	vector<int> l(n), r(n);
	vector<P> p(n);
	rep(i, n) {
		cin >> l[i] >> r[i];
		l[i]--; r[i]--;
		p[i].first = r[i] - l[i] + 1;
		p[i].second = l[i];
	}
	sort(all(p));
	vector<int> ans(m + 2);
	rep(i, n) ans[p[i].first]++;
	for (int i = m - 1; i >= 1; i--) ans[i] += ans[i + 1];
	segtree<int> seg(m, 0, [](int a, int b) {return a + b; }, [](int a, int b) {return a + b; });
	int idx = 0;
	for (int i = 1; i <= m; i++) {
		while (idx < n && p[idx].first == i - 1) {
			seg.change(p[idx].second, p[idx].first + p[idx].second, 1);
			idx++;
		}
		for (int j = i; j <= m; j += i) ans[i] += seg.get(j - 1);
	}
	rep(i, m) cout << ans[i + 1] << endl;
}