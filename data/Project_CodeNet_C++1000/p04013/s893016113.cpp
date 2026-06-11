#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(V) V.begin(),V.end()
#define MOD 1000000007

ll dp[53][53][2520];

int main() {
	int N, A;
	cin >> N >> A;
	vector<int> X(N);
	for (int i = 0;i < N;i++) {
		cin >> X[i];
	}

	dp[0][0][0] = 1;
	for (int i = 0;i < N;i++) {//何個使いましたか
		for (int j = 0;j < N;j++) {//何個目まで見ましたか
			for (int k = 0;k < 2520;k++) {//現在の値は何ですか
				if (k + X[j] < 2520)
					dp[i + 1][j + 1][k + X[j]] += dp[i][j][k];
				dp[i][j + 1][k] += dp[i][j][k];
			}
		}
	}
	ll ans = 0;
	for (int i = 1;i <= N;i++) {
		ans += dp[i][N][i * A];
	}
	cout << ans << endl;
}