#include <bits/stdc++.h>
using namespace std;

const int MAXN = 112345;
const long long MOD = 1e9 + 7;

long long n, m;
vector <long long> x;
vector <long long> y;

long long solve () {
	long long ans = 0;
	for (long long i = 1; i < n; ++i) {
		long long temp = i * (n - i);
		temp %= MOD;
		
		ans += temp * (x[i] - x[i - 1]);
		ans %= MOD;
	}
	
	// ans *= ( ((m - 1LL) * m) / 2LL ) % MOD;
	return ans;
}

int main () {

	cin >> n >> m;
	x.resize (n);
	y.resize (m);
	
	for (int i = 0; i < n; ++i)
		scanf ("%lld", &x[i]);
		
	for (int i = 0; i < m; ++i)
		scanf ("%lld", &y[i]);

	long long ans = solve ();
	swap (n, m);
	swap (x, y);
	ans *= solve ();
	ans %= MOD;
	cout << ans << endl;

	return 0;
}