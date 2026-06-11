// In the Name of God

#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

#define	ll long long
#define ull unsigned long long
#define ld long double
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define sz(a) int(a.size())
#define all(v) v.begin(), v.end()
#define bpc(v) __builtin_popcountll(v)
#define itr iterator
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define per(i, a, b) for (int i = a; i >= b; --i)
#define ub upper_bound
#define lb lower_bound

const int N = 2e5 + 5;
const ll mod = 1e9 + 7;
const int inf = 1e9 + 1;
const double eps = 1e-15;
const int pw = 257;

int h, w, a, b;
ll f[N], ans;

inline ll binpow(ll x, ll n) {
	ll res = 1;
	while (n) {
//		cerr << n << "\n";
		if (n % 2 == 1)
			res = (res * x) % mod;
		x = (x * x) % mod;
		n /= 2;
	}
	return res;
}

inline ll c(int n, int k) {
	return (((f[n] * binpow(f[k], mod - 2)) % mod) * binpow(f[n - k], mod - 2)) % mod;
}

int main() {
	#ifdef Madi
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
	#endif
	                                            	
	ios_base :: sync_with_stdio(false); cin.tie(NULL);

	f[0] = 1;
	rep(i, 1, 200000)
		f[i] = (f[i - 1] * i) % mod;

    cin >> h >> w >> a >> b;
    rep(i, b, w - 1)
    	ans = (((c(h - a - 1 + i, h - a - 1) * c(a - 1 + w - i - 1, a - 1)) % mod) + ans) % mod;

    cout << ans;

	#ifdef Madi
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}