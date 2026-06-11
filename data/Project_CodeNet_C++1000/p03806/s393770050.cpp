#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

const int INF = 1 << 30;

int main() {
	int N, Ma, Mb;
	cin >> N >> Ma >> Mb;
	vector<int> A(N), B(N), C(N);
	for (int i = 0; i < N; i++)
		cin >> A[i] >> B[i] >> C[i];
	
	vector<vector<vector<int>>> dp(N+1,
		vector<vector<int>>(10*N+1,
			vector<int>(10*N+1)));
	for (int i = 0; i < N+1; i++) {
		for (int j = 0; j < 10*N+1; j++) {
			for (int k = 0; k <10*N+1; k++) {
				dp[i][j][k] = INF;
			}
		}
	}

	dp[0][0][0] = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 10*N; j++) {
			for (int k = 0; k < 10*N; k++) {
				if (j+A[i] > 10*N || k+B[i] > 10*N) continue;
				dp[i+1][j+A[i]][k+B[i]] = min(dp[i+1][j+A[i]][k+B[i]], dp[i][j][k] + C[i]);
				dp[i+1][j][k] = min(dp[i+1][j][k], dp[i][j][k]);
			}
		}
	}

	int ans = INF;
	for (int i = 1; i <= 10*N; i++) {
		if (Ma*i > 10*N || Mb*i > 10*N) break;
		ans = min(ans, dp[N][Ma*i][Mb*i]);
	}
	if (ans == INF) ans = -1;
	cout << ans << endl;
}
