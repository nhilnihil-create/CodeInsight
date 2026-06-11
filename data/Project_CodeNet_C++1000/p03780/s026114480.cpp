#include <iostream>
#include <algorithm>
using namespace std;
int N, K, a[5009], s[5009]; bool dp[5009], dpr[5009][5009];
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> a[i];
	dpr[N][0] = true;
	for (int i = N - 1; i >= 0; i--) {
		for (int j = 0; j < K; j++) dpr[i][j] = dpr[i + 1][j];
		for (int j = a[i]; j < K; j++) {
			if (dpr[i + 1][j - a[i]]) dpr[i][j] = true;
		}
	}
	dp[0] = true;
	int ret = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) s[j + 1] = s[j] + dp[j];
		bool ok = false;
		for (int j = 0; j < K; j++) {
			if (dpr[i + 1][j] && s[K - j] != s[max(K - j - a[i], 0)]) ok = true;
		}
		for (int j = K - 1; j >= a[i]; j--) {
			if (dp[j - a[i]]) dp[j] = true;
		}
		if(!ok) ret++;
	}
	cout << ret << endl;
	return 0;
}