#include <bits/stdc++.h>
#define int long long
#define range(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i, a) range(i, 0, a)
using namespace std;
const int INF = sizeof(int) == sizeof(long long) ? LLONG_MAX : INT_MAX;
const int MOD = 1000000007LL;
const long double EPS = 1e-8;

signed main() {
	int n, m;
	cin >> n >> m;
	int x[n], y[m];
	rep (i, n) cin >> x[i];
	rep (i, m) cin >> y[i];
	int prev = 0, next = 0;
	range (i, 1, n) prev = ((prev + (x[n - i] * (n - i)) % MOD) % MOD - (MOD + (x[i - 1] * (n - i)) % MOD)) % MOD;
	range (i, 1, m) next = ((next + (y[m - i] * (m - i)) % MOD) % MOD - (MOD + (y[i - 1] * (m - i)) % MOD)) % MOD;
	cout << prev * next % MOD << endl;
	return 0;
}