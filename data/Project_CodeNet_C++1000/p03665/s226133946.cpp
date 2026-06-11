#include <iostream>
#include <map>
#include <queue>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
#pragma warning (disable: 4996)

long long N, P, A[1 << 18];
long long dp[59][2];

int main() {
	cin >> N >> P;
	for (int i = 1; i <= N; i++) cin >> A[i];
	dp[0][0] = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 2; j++) {
			dp[i][j] += dp[i - 1][j];
			dp[i][j ^ (A[i] % 2)] += dp[i - 1][j];
		}
	}
	cout << dp[N][P] << endl;
	return 0;
}