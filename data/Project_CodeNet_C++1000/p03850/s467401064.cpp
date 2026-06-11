#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
const double PI = 3.141592653589793238;
const double EPS = 1e-10;
ll A[100000];
string op[100000];
ll dp[100000][3];
int main() {
	int N;
	cin >> N;
	cin >> A[0];
	for (int i = 0; i + 1 < N; i++) {
		cin >> op[i] >> A[i + 1];
	}
	fill((ll*)dp, (ll*)(dp + N), -INF);
	dp[0][0] = A[0];
	for (int i = 0; i + 1 < N; i++) {
		for (int j = 0; j < 3; j++) {
			if (dp[i][j] == -INF) continue;
			if (op[i] == "+") {
				if (j % 2 == 0) dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + A[i + 1]);
				else dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] - A[i + 1]);
				if (j > 0) {
					if (j % 2 == 0) dp[i + 1][j - 1] = max(dp[i + 1][j - 1], dp[i][j] - A[i + 1]);
					else dp[i + 1][j - 1] = max(dp[i + 1][j - 1], dp[i][j] + A[i + 1]);
				}
			}
			else {
				if (j > 0) {
					if (j % 2 == 0) dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + A[i + 1]);
					else dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] - A[i + 1]);
				}
				if (j < 2) {
					if (j % 2 == 0) dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] - A[i + 1]);
					else dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + A[i + 1]);
				}
			}
		}
	}
	ll ans = -INF;
	for (int i = 0; i < 3; i++) {
		ans = max(ans, dp[N - 1][i]);
	}
	cout << ans << endl;
}
