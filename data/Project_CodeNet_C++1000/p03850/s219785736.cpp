#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;
ll dp[100010][3];
char op[100010];
ll A[100010];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	op[0] = '+';
	for(int i = 0; i < N; i++) {
		cin >> A[i];
		if(i != N - 1) cin >> op[i + 1];
	}

	fill((ll*)begin(dp), (ll*)end(dp), -INF);
	dp[0][0] = 0;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j <= 2; j++) {
			if(dp[i][j] == -INF) continue;
			ll d = dp[i][j];
			if(op[i] == '+') {
				for(int k = 0; k <= j; k++) {
					if(j % 2 == 0) {
						dp[i + 1][k] = max(dp[i + 1][k], d + A[i]);
					}
					else {
						dp[i + 1][k] = max(dp[i + 1][k], d - A[i]);
					}
				}
			}
			else {
				int nj = min(2, j + 1);
				for(int k = 0; k <= min(2, j + 1); k++) {
					if((j + 1) % 2 == 0) {
						dp[i + 1][k] = max(dp[i + 1][k], d + A[i]);
					}
					else {
						dp[i + 1][k] = max(dp[i + 1][k], d - A[i]);
					}
				}
			}
		}
	}

	cout << dp[N][0] << endl;
}