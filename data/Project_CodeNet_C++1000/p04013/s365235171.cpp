#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll dp[51][2500];

int main() {

	ll n, a; scanf("%lld %lld", &n, &a);

	dp[0][0] = 1;

	for (int i = 0; i < n; i++) {

		ll x; scanf("%lld", &x);

		for (int j = n - 1; j >= 0; j--)
			for (int w = 0; w + x <= 2500; w++)
				dp[j + 1][w + x] += dp[j][w];

	}

	ll ans = 0;

	for (int i = 1; i <= n; i++) ans += dp[i][i * a];

	printf("%lld", ans);

	return 0;

}