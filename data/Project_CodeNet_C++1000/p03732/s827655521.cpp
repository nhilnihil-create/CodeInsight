#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, W;
	cin >> N >> W;
	vector<int> w(N), v(N);
	for (int i = 0; i < N; i++) cin >> w[i] >> v[i];

	vector<vector<vector<int>>> dp(N+1,
		vector<vector<int>>(N+1,
			vector<int>(3*N+1)));
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 0; k <= 3*N; k++) {
				int k_prev = k - w[i-1] + w[0];
				if (k_prev < 0 || k_prev > 3*N) {
					dp[i][j][k] = dp[i-1][j][k];
				}
				else {
					dp[i][j][k] = max(dp[i-1][j][k], dp[i-1][j-1][k_prev] + v[i-1]);
				}
			}
		}
	}

	int a = min(N, W/w[0]);
	int b = min(3*N, W-w[0]*a);
	int ans = 0;
	while(a >= 0 && b <= 3*N) {
		ans = max(ans, dp[N][a][b]);
		a--;
		b = W-w[0]*a;
	}
	cout << ans << endl;	
}
