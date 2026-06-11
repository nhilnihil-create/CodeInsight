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
#define INF 1000000009
#define LINF 1000000000000000009
#define EPS 1e-10
#define PI 3.141592653589793238
#define all(a) a.begin(),a.end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<ll, P> PP;
template<class T> bool chmax(T &a, const T&b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T&b) { if (a > b) { a = b; return 1; } return 0; }
ll gcd(ll n, ll m) { return (m ? gcd(m, n%m) : n); }
ll lcm(ll n, ll m) { return n / gcd(n, m)*m; }

template<class T>
class segtree {
	int n;
	vector<T> data;
	T def;
	function<T(T, T)> operation;
	function<T(T, T)> update;
	T _query(int a, int b, int k, int l, int r) {
		if (r <= a || b <= l) return def;
		if (a <= l && r <= b) return data[k];
		T c1 = _query(a, b, 2 * k + 1, l, (l + r) / 2);
		T c2 = _query(a, b, 2 * k + 2, (l + r) / 2, r);
		return operation(c1, c2);
	}
public:
	segtree(size_t _n, T _def, function<T(T, T)> _operation, function<T(T, T)> _update)
		:def(_def), operation(_operation), update(_update) {
		n = 1;
		while (n < _n) {
			n *= 2;
		}
		data = vector<T>(2 * n - 1, def);
	}
	void change(int i, T x) {
		i += n - 1;
		data[i] = update(data[i], x);
		while (i > 0) {
			i = (i - 1) / 2;
			data[i] = operation(data[i * 2 + 1], data[i * 2 + 2]);
		}
	}
	T query(int a, int b) {
		return _query(a, b, 0, 0, n);
	}
	T operator[](int i) {
		return data[i + n - 1];
	}
};

int main() {
	ll n, x;
	cin >> n >> x;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	segtree<ll> seg(2 * n, LINF, [](ll a, ll b) {return min(a, b); }, [](ll a, ll b) {return b; });
	for (int i = 0; i < n; i++) {
		seg.change(i, a[i]);
		seg.change(n + i, a[i]);
	}
	ll ans = LINF;
	for (ll i = 0; i < n; i++) {
		ll cnt = i * x;
		for (int j = n; j < 2 * n; j++) {
			cnt += seg.query(j - i, j + 1);
		}
		chmin(ans, cnt);
	}
	cout << ans << endl;
}