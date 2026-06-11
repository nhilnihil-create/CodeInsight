#include <iostream>
#include <vector>
#include <algorithm>

#define INF 1010101010

using namespace std;
int dp[41][401][401];
int main()
{
	int n, ma, mb;
	cin >> n >> ma >> mb;
	vector<int> a(n), b(n), c(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i] >> c[i];
	}

	
	for (int i = 0; i < 41; i++) {
		for (int j = 0; j < 401; j++) {
			for (int k = 0; k < 401; k++) {
				dp[i][j][k] = INF;
			}
		}
	}
	dp[0][0][0] = 0;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= 400; j++) {
			for (int k = 0; k <= 400; k++) {
				if (j - a[i - 1] >= 0 && k - b[i - 1] >= 0) {
					dp[i][j][k] = min(dp[i - 1][j][k], dp[i - 1][j - a[i - 1]][k - b[i - 1]] + c[i - 1]);
				}
				else {
					dp[i][j][k] = dp[i - 1][j][k];
				}
			}
		}
	}

	int mn = INF;
	int s = ma, t = mb;
	while (s <= 400 && t <= 400) {
		mn = min(mn, dp[n][s][t]);
		s += ma;
		t += mb;
	}
	cout << (mn == INF ? -1 : mn) << endl;

	return 0;
}