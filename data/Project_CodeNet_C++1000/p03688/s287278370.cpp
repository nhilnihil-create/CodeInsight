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

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

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
	int n, x;
	cin >> n;
	vector<int> a(n);
	rep (i, n) cin >> a[i];
	bool two = false;
	rep (i, n) two |= (a[i] != a[0]);
	if (!two) {
		if (n / a[0] >= 2 || n == a[0] + 1) cout << "Yes\n";
		else cout << "No\n";
	} else {
		bool small = false;
		int p = 0, q = 0;
		rep (i, n) {
			small |= (a[i] < a[0]);
			if (a[i] != a[0]) {
				if (abs(a[i] - a[0]) != 1) {
					cout << "No\n";
					return 0;
				}
			}
		}
		if (small) {
			rep (i, n) {
				if (a[i] < a[0]) p++;
				else q++;
			}
		} else {
			rep (i, n) {
				if (a[i] > a[0]) q++;
				else p++;
			}
		}
		x = a[0] + (!small);
		if (p + 1 <= x && x <= p + (n - p) / 2) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}