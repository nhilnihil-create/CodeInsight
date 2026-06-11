#include <bits/stdc++.h>
using namespace std;

int n, a, x[55];
long long ans, dp[55][3000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 	
	cin >> n >> a;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}

	dp[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = n-1; j >= 0; j--) {
			for (int k = 0; k <= 2500; k++) {
				if (dp[j][k]) {
					dp[j + 1][k + x[i]] += dp[j][k];
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		ans += dp[i][a * i];
	}
	cout << ans << '\n';

	return 0;
}