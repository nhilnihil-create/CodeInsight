#include <bits/stdc++.h>
using namespace std;
//#define cerr if (false) cerr
#define db(x) cerr << #x << "=" << x << endl
#define db2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << endl
#define db3(x, y, z) cerr << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl
#define dbv(v) cerr << #v << "="; for (auto _x : v) cerr << _x << ", "; cerr << endl
#define dba(a, n) cerr << #a << "="; for (int _i = 0; _i < (n); ++_i) cerr << a[_i] << ", "; cerr << endl
template <typename A, typename B>
ostream& operator<<(ostream& os, const pair<A, B>& x) {
	return os << "(" << x.first << "," << x.second << ")";
}
typedef long long ll;
typedef long double ld;
template <typename T>
struct Fenwick {
	int n;
	vector<T> bit;
	Fenwick(int _n) : n(_n) {
		bit.resize(n + 1);
	}
	void update(int p, T v) {
		for (; p <= n; p += p & -p) bit[p] += v;
	}
	T query(int p) {
		T ret{};
		for (; p; p -= p & -p) ret += bit[p];
		return ret;
	}
	// multiset with count strictly less; values contain all inserted values
	vector<ll> values;
	Fenwick(vector<ll>& _values) : values(_values) {
		sort(values.begin(), values.end());
		n = unique(values.begin(), values.end()) - values.begin();
		values.resize(n);
		bit.resize(n + 1);
	}
	void insert(ll val) {
		int pos = lower_bound(values.begin(), values.end(), val) - values.begin();
		update(pos + 1, 1);
	}
	int countLess(ll val) {
		int pos = lower_bound(values.begin(), values.end(), val) - values.begin();
		return query(pos);
	}
	// Assumes val already exists
	void erase(ll val) {
		int pos = lower_bound(values.begin(), values.end(), val) - values.begin();
		update(pos + 1, -1);
	}
};
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	vector<int> a(n);
	vector<ll> S(n + 1);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		S[i + 1] = S[i] + a[i] - k;
	}
	Fenwick<int> fenw(S);
	fenw.insert(0);
	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		ans += fenw.countLess(S[i] + 1);
		fenw.insert(S[i]);
	}
	printf("%lld\n", ans);
}
