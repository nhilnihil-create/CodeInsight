#include <iostream>
using namespace std;
 
int main() {
	int N, A;
	cin >> N >> A;
	int x[53];
	int sum = 0;
	for (int i = 0; i < N; i++) {
		cin >> x[i];
		sum += x[i];
	}
	long long dp[53][2550][53] = { 0 };
	dp[0][0][0] = 1;
	for (int i = 0; i < N; i++) {
		for (int k = 0; k <= i+1; k++) {
			for (int j = 0; j <= sum; j++) {
				if (j >= x[i]&&k>0) {
					dp[i + 1][j][k] = dp[i][j - x[i]][k - 1] + dp[i][j][k];
				}
				else {
					dp[i + 1][j][k] = dp[i][j][k];
				}
			}
		}
	}
	long long combi;
	combi = 0;
	for (int i = 1; i <= N; i++) {
			combi += dp[N][i*A][i];
	}
	cout << combi;
	return 0;
}