#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
int main()
{
	int n;
	string str;
	cin >> n >> str;
	vector<vector<ll> > dp(n + 1, vector<ll>(n + 1, 0));
	dp[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= n; j++) {
			(dp[i + 1][j + 1] += dp[i][j] * 2) %= MOD;
			(dp[i + 1][max(j - 1, 0)] += dp[i][j]) %= MOD;
		}
	}
	ll ans = dp[n][str.size()];
	for (int i = 0; i < str.size(); i++) {
		ans = ans * (MOD + 1) / 2 % MOD;
	}
	cout << ans << endl;
	return 0;
}
