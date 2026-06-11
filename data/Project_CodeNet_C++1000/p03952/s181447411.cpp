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

#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; ++i)
#define repp(i, m, n) for(int i = m, i##_len = (n); i < i##_len; ++i)
#define reprev(i, n) for(ll i = (n-1LL); i >= 0; --i)
#define all(x) (x).begin(), (x).end()
template <class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template <class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }
template <class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <ll,ll> P;
typedef long double ld;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, x;
	cin >> n >> x;
	if (x == 1 || x == 2 * n - 1) {
		cout << "No\n";
	} else {
		cout << "Yes\n";
		if (x == n) {
			rep (i, 2 * n - 1) {
				cout << i + 1 << "\n";
			}
		} else if (x < n) {
			int y = 2 * n - x, nn = 2 * n - 1;
			repp (i, y + 1 - n, y + 1) cout << nn - i << "\n";
			rep (i, y + 1 - n) cout << nn - i << "\n";
			repp (i, y + 1, 2 * n - 1) cout << nn - i << "\n";
		} else {
			repp (i, x + 1 - n, x + 1) cout << i + 1 << "\n";
			rep (i, x + 1 - n) cout << i + 1 << "\n";
			repp (i, x + 1, 2 * n - 1) cout << i + 1 << "\n";
		}
	}
	return 0;
}