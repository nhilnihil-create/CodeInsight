#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>

#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; ++i)
#define repp(i, m, n) for(ll i = m, i##_len = (n); i < i##_len; ++i)
#define all(x) (x).begin(), (x).end()
#define clr(ar, val) memset(ar, val, sizeof(ar))
template <class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template <class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }
template <class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <ll,ll> P;
typedef long double ld;

template <class T> T div_minus (T a, T b) {
	if (a % b < 0) return a / b - 1;
	else return a / b;
}
template <class T> T mod_minus (T a, T b) {
	if (a % b < 0) return a % b + b;
	else return a % b;
}
int main(void)
{
	ll n, l, t;
	cin >> n >> l >> t;
	vector<ll> x(n), w(n);
	vector<P> res(n);
	rep (i, n) {
		cin >> x[i] >> w[i];
		if (w[i] == 1) res[i].first = (x[i] + t) % l;
		else res[i].first = mod_minus(x[i] - t, l);
		res[i].second = i;
	}
	ll count = 0;
	repp (i, 1, n) {
		if (w[0] == 1) {
			if (w[i] == 2) {
				// cout << i << ": " << div_minus(2 * t - (x[i] - x[0]), l) + 1 << endl;
				count += div_minus(2 * t - (x[i] - x[0]), l) + 1;
			}
		} else {
			if (w[i] == 1) {
				// cout << i << ": " << div_minus(2 * t - (l + x[0] - x[i]), l) + 1 << endl;
				count -= div_minus(2 * t - (l + x[0] - x[i]), l) + 1;
			}
		}
	}
	sort(all(res));
	ll k;
	for (k = 0; k < n; k++) {
		if (res[k].second == 0) break;
	}
	if (w[0] == 1 && res[(k + 1) % n].first == res[k].first) k++;
	// cout << count << " " << k << endl;
	count = mod_minus(k - count, n);
	rep(i, n) {
		cout << res[(i + count) % n].first << endl;
	}
	return 0;
}