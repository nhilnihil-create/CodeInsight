#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

const lli MOD = 1e9 + 7;
const lli N = 1e6 + 5;
lli n;
lli dp[N+1];

int main() {
	cin >> n;

	dp[1] = n;
	dp[2] = n*n % MOD;
	lli sum = dp[1] + dp[2];
	sum %= MOD;
	for(lli i = 3; i <= n; i++) {
		dp[i] = (n-1)*(n-1) + sum - dp[i-2] + n - i + 2;
		dp[i] += MOD;
		dp[i] %= MOD;
		sum += dp[i];
		sum %= MOD;
	}
	cout << dp[n] << endl;

	return 0;
}