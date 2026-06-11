#include<iostream>
//abc054_d
using namespace std;
int dp[401][401][41];
int main() {

	int n, ma, mb;
	cin >> n >> ma >> mb;
	int i, j, k;
	int a[41], b[41], c[41];
	for (i = 1; i <= n; i++) {
		cin >> a[i] >> b[i] >> c[i];
	}


	for (i = 0; i <= 400; i++) {
		for (j = 0; j <= 400; j++) {
			for (k = 0; k <= 41; k++) {
				dp[i][j][k] = 100000000;
			}
		}
	}
	dp[0][0][0] = 0;

	for (k = 1; k <= n; k++) {
		for (i = 0; i <= 400; i++) {
			for (j = 0; j <= 400; j++) {
				dp[i][j][k] = dp[i][j][k - 1];
				if (i - a[k] >= 0 && j - b[k] >= 0) {
					if (dp[i - a[k]][j - b[k]][k - 1] + c[k] < dp[i][j][k]) {
						dp[i][j][k] = dp[i - a[k]][j - b[k]][k - 1] + c[k];
					}
				}
			}
		}
	}

	k = dp[ma][mb][n];
	i = ma;
	j = mb;
	while (i <= 400 && j <= 400) {
		if (dp[i][j][n] < k) {
			k = dp[i][j][n];
		}
		i += ma;
		j += mb;
	}
	if (k == 100000000) {
		cout << -1 << endl;
		return 0;
	}
	cout << k << endl;
	return 0;



}