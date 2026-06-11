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
	for (int i = 1; i < N; i++) {
		cin >> op[i - 1];
		cin >> A[i];
	}
	fill((ll*)dp, (ll*)(dp + N), -(1LL << 60));
	dp[0][0] = A[0];
	for (int i = 0; i + 1 < N; i++) {
		for (int j = 0; j <= 2; j++) {
			if (dp[i][j] == -(1LL << 60)) continue;
			for (int k = 0; k <= j; k++) {
				if (op[i] == "+") {
					dp[i + 1][k] = max(dp[i + 1][k], dp[i][j] + A[i + 1] * (k % 2 == 0 ? 1 : -1));
				}
				else if (k <= 1) {
					dp[i + 1][k + 1] = max(dp[i + 1][k + 1], dp[i][j] + A[i + 1] * (k % 2 == 0 ? -1 : 1));
				}
			}
		}
	}
	ll ans = max(dp[N - 1][0], dp[N - 1][1]);
	ans = max(ans, dp[N - 1][2]);
	cout << ans << endl;
}