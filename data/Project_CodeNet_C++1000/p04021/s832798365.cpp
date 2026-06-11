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
	vector<int> a(n), b((n + 1) / 2);
	rep (i, n) cin >> a[i];
	rep (i, (n + 1) / 2) b[i] = a[2 * i];
	sort(all(a));
	rep (i, (n + 1) / 2) eprintf("%d ", a[2 * i]); eprintf("\n");
	rep (i, (n + 1) / 2) eprintf("%d ", b[i]); eprintf("\n");
	map<int, int> m;
	rep (i, (n + 1) / 2) {
		m[a[2 * i]]++;
		m[b[i]]--;
	}
	ll ans = 0;
	for (auto x : m) {
		if (x.second > 0) ans += x.second;
	}
	cout << ans << "\n";
	return 0;
}