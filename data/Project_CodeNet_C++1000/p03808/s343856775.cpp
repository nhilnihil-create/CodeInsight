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
#include <stack>
#include <functional>

#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; ++i)
#define repp(i, m, n) for(ll i = m, i##_len = (n); i < i##_len; ++i)
#define reprev(i, n) for(ll i = (n-1LL); i >= 0; --i)
#define all(x) (x).begin(), (x).end()
template <class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template <class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }
template <class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int,int> P;
typedef long double ld;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n, sum = 0, k;
	cin >> n;
	vector<ll> a(n);
	rep (i, n) {
		cin >> a[i];
		sum += a[i];
	}
	if ((2 * sum) % n == 0 && (2 * sum) % (n + 1) == 0) {
		k = (2 * sum) / n;
		k /= n + 1;
		// cout << k << "\n";
		bool ok = true;
		rep (i, n) {
			if ((k - (a[(i + 1) % n] - a[i])) % n != 0 || (k - (a[(i + 1) % n] - a[i])) / n < 0) ok = false;
		}
		cout << (ok ? "YES" : "NO") << "\n";
	} else {
		cout << "NO\n";
	}
	return 0;
}