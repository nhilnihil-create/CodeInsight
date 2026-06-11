#include <bits/stdc++.h>
using namespace std;

const int N = 1000 * 3;

long long n, x, sum, ans;
long long dp[N][N], a[N];

int main() {
	cin >> n >> x;
	for (int i = 0; i < n; i++) 
		cin >> a[i];
	for (int i = 0; i < n; i++) {
		dp[0][i] = a[i];
		ans += a[i];
	}
	for (int j = 1; j < n; j++) {
		sum = j * x;
		dp[j][0] = min(a[0], dp[j - 1][n - 1]);
		sum += dp[j][0];
		for (int i = 1; i < n; i++) {
			dp[j][i] = min(a[i], dp[j - 1][i - 1]);
			sum += dp[j][i];
		}
		ans = min(ans, sum);
	}
	cout << ans;
	return 0;
}