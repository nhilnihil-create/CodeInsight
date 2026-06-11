#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int const MAX = 5005;
long long const MOD = 1000000007;
long long dp[MAX][MAX];

long long mult_mod(long long x,long long y) {
	return (x*y) % MOD;
}
long long plus_mod(long long x, long long y) {
	return (x + y) % MOD;
}

int main() {
	int n, m; string s;
	cin >> n >> s;
	m = s.size();
	dp[0][0] = 1;
	for (int i = 0; i <= n; i++) {
		dp[i][i + 1] = 0;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) {
				dp[i][j] = plus_mod(dp[i - 1][0], mult_mod(2, dp[i - 1][1]));
			}
			else {
				dp[i][j] = plus_mod(dp[i - 1][j - 1], mult_mod(2, dp[i - 1][j + 1]));
			}
		}
	}
	cout << dp[n][m] << endl;
}
