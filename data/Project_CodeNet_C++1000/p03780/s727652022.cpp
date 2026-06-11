#include <iostream>
using namespace std;

int dp1[5009][5009], dp2[5009][5009], n, k, a[5009], p1[5009], p2[5009];

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	dp1[0][0] = 1;
	for (int i = 0; i <= n - 1; i++) {
		for (int j = 0; j <= k; j++) {
			if (dp1[i][j] == 0) continue;
			dp1[i + 1][j] = 1;
			if (j + a[i + 1] <= k) dp1[i + 1][j + a[i + 1]] = 1;
		}
	}
	dp2[n + 1][0] = 1;
	for (int i = n + 1; i >= 2; i--) {
		for (int j = 0; j <= k; j++) {
			if (dp2[i][j] == 0) continue;
			dp2[i - 1][j] = 1;
			if (j + a[i - 1] <= k) dp2[i - 1][j + a[i - 1]] = 1;
		}
	}

	int ret = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= k; j++) { p1[j] = 0; p2[j] = 0; }
		for (int j = 0; j <= k; j++) p1[j] = dp1[i - 1][j];
		for (int j = 0; j <= k; j++) p2[j] = dp2[i + 1][j];
		for (int j = 1; j <= k; j++) p2[j] += p2[j - 1];
		
		int L = k - a[i], R = k, sum = 0; if (L < 0) L = 0;

		for (int j = 0; j <= k; j++) {
			if (p1[j] == 0) continue;

			int S1 = L - j, S2 = R - j; if (S1 < 0) S1 = 0;
			int F1 = 0; if (S2 >= 1) F1 += p2[S2 - 1];
			if (S1 >= 1) F1 -= p2[S1 - 1];

			sum += F1;
		}
		if (sum == 0) ret++;
	}
	cout << ret << endl;
	return 0;
}