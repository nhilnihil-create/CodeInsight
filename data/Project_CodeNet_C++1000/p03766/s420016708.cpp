#include <bits/stdc++.h>

#define pb push_back

typedef long long ll;

using namespace std;

const int MOD = 1000000007;

ll n;
ll dp[1000010], s[1000010];

int main() {
	cin >> n;
	dp[n] = n;
	dp[n + 1] = 1;
	s[n] = n + 1;
	s[n + 1] = 1;
	for (int i = n - 1; i >= 1  ; --i) {
		dp[i] = ((n - 1) * 1ll * (n - 1) + i + dp[i + 1] + s[i + 3] + MOD) % MOD;
		s[i] = (s[i + 1] + dp[i]) % MOD;
	}
	cout << dp[1] << endl;
	return 0;
}