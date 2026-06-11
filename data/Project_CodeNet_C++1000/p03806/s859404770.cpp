#include <bits/stdc++.h>
using namespace std;

int n, ma, mb, ans, a[45], b[45], c[45], dp[45][405][405];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 	
	cin >> n >> ma >> mb;

	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i] >> c[i];
	}

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= 400; j++) {
			for (int k = 0; k <= 400; k++) {
				dp[i][j][k] = 1e9;
			}
		}
	}

	dp[0][0][0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= 400; j++) {
			for (int k = 0; k <= 400; k++) {
				if (dp[i-1][j][k] != 1e9) {
					dp[i][j][k] = min(dp[i][j][k], dp[i-1][j][k]);
					dp[i][j+a[i]][k+b[i]] = min(dp[i][j+a[i]][k+b[i]], dp[i-1][j][k] + c[i]);
				}
			}
		}
	}

	ans = 1e9;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= 400; j++) {
			for (int k = 0; k <= 400; k++) {
				if (dp[i][j][k] != 1e9) {
					int gcd = __gcd(j, k);
					if (gcd == 0) {
						continue;
					}

					if (ma == j/gcd && mb == k/gcd) {
						ans = min(ans, dp[i][j][k]);
					}
				}
			}
		}
	}

	if (ans == 1e9) {
		cout << "-1\n";
	}
	else {
		cout << ans << '\n';
	}
	
	return 0;
}