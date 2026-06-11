#include <iostream>

using namespace std;

int main(){
	long long N, A, x[51], X = 0;
	cin >> N >> A;
	x[0] = 0;
	for (long long i = 1; i <= N; i++){
		cin >> x[i];
		if (X < x[i]){
			X = x[i];
		}
		x[i] -= A;
	}

	long long dp[N + 1][2 * N * X + 1];
	for (int j = 0; j <= N; j++){
		for (int t = 0; t <= 2 * N * X; t++){
			dp[j][t] =
				(j == 0 && t == N * X) ? 1 :
				(j > 0 && (t - x[j] < 0 || t - x[j] > 2 * N * X)) ? dp[j - 1][t] :
				(j > 0 && 0 <= t - x[j] && t - x[j] <= 2 * N * X) ? dp[j - 1][t] + dp[j - 1][t - x[j]] :
				0;
		}
	}

	cout << dp[N][N * X] - 1 << endl;

	return 0;
}
