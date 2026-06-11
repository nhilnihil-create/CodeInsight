#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
constexpr ll MODN = 1000000007;
ll n, dp[1000001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n, dp[0] = 1, dp[1] = dp[0] + n;
	for (int i = 2; i <= n; ++i) {
		dp[i] = (n - 1) * (n - 1);
		int l = i - (n + 1), r = i - 3;
		if (r >= 0) dp[i] += dp[r], r = -1;
		dp[i] += r - l + 1;
		dp[i] += 2 * dp[i - 1] - dp[i - 2];
		dp[i] %= MODN;
	}
	cout << (dp[n] - dp[n - 1] + MODN) % MODN << endl;
	return 0;
}