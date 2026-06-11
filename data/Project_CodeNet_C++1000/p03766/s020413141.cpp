#include <bits/stdc++.h>
using namespace std;

#define int long long
int MOD = 1000000007;
signed main() {
	int n;
	cin >> n;
	if (n == 1) {
		cout << 1 << endl; return 0;
	}
	if (n == 2) {
		cout << 4 << endl; return 0;
	}
	if (n == 3) {
		cout << 15 << endl; return 0;
	}
	vector<int> dp(n+5);
	dp[0] = n-1;
	dp[1] = n*n - n;
	dp[2] = n*n - n;
	int sum = dp[0] + dp[1] + dp[2];
	for (int i = 3; i < n; i++) {
		dp[i] = ((sum - dp[i - 2]) + MOD) % MOD;
		sum = (sum + dp[i]) % MOD;
	}
	cout << ((sum+1) % MOD) << endl;
	return 0;
}