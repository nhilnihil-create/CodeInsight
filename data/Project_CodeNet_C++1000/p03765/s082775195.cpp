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

int mod (int a, int b) {
	return ((a % b) + b) % b;
}
int main(void)
{
	string s, t;
	cin >> s >> t;
	int x[2][100001] = {}, y[2][100001] = {};
	rep (i, s.size()) {
		int tmp = (s[i] == 'A');
		x[0][i + 1] = x[0][i] + tmp;
		x[1][i + 1] = x[1][i] + (!tmp);
		// eprintf("%d/%d ", x[0][i + 1], x[1][i + 1]);
	}
	// eprintf("\n");
	rep (i, t.size()) {
		int tmp = (t[i] == 'A');
		y[0][i + 1] = y[0][i] + tmp;
		y[1][i + 1] = y[1][i] + (!tmp);
		// eprintf("%d/%d ", y[0][i + 1], y[1][i + 1]);
	}
	// eprintf("\n");
	int q;
	cin >> q;
	rep (i, q) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		int xx[2], yy[2];
		rep (j, 2) {
			xx[j] = x[j][b] - x[j][a - 1];
		}
		rep (j, 2) {
			yy[j] = y[j][d] - y[j][c - 1];
		}
		eprintf("%d %d -> %d %d\n", xx[0], xx[1], yy[0], yy[1]);
		if (mod(yy[0] - xx[0], 3) == mod(yy[1] - xx[1], 3)) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	return 0;
}