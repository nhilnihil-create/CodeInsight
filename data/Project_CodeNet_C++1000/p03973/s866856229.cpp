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
	int n;
	cin >> n;
	vector<int> a(n);
	rep (i, n) cin >> a[i];
	rep (i, n) eprintf("%d ", a[i]); eprintf("\n");
	ll now_min = 0, ans = 0;
	rep (i, n) {
		if (a[i] > now_min + 1) {
			ans += (a[i] - 1) / (now_min + 1);
			chmax(now_min, 1LL);
		} else {
			chmax(now_min, (ll)a[i]);
		}
	}
	cout << ans << "\n";
	return 0;
}