#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstdio>
using namespace std;
long long dp[100][100][5000]; long long n, k, x[100];
int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++)cin >> x[i]; dp[0][0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < 5000; k++) {
				if (dp[i][j][k] == 0)continue;
				dp[i + 1][j+1][k + x[i]] += dp[i][j][k];
				dp[i + 1][j][k] += dp[i][j][k];
			}
		}
	}
	long long sum = 0;
	for (int i = 1; i <= n; i++)sum += dp[n][i][k*i];
	cout << sum << endl;
	return 0;
}
