#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

signed main(){
	int n,dp[1000010] = {1,1,1,2},ans = 0;
	cin >> n;
	for(int i = 4;i <= n;i++) dp[i] = (dp[i - 4] + dp[i - 2] + dp[i - 1]) % MOD;
	for(int i = 0;i < n - 2;i++) (ans += dp[i] * ((n - 1) * (n - 1) % MOD + i + 2)) %=  MOD;
	(ans += dp[n - 2] * ((n - 1) * (n - 1) % MOD + n - 1)) %= MOD;
	(ans += dp[n - 1] * n) %= MOD;
	cout << ans << endl;
	return 0;
}