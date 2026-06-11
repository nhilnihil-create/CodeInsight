#include<iostream>
using namespace std;
int DP(int x, int y);
int dp[3001][3001];
int a, b, c, d, e, f;
int main() {


	int i, j;
	for (i = 0; i <= 3000; i++) {
		for (j = 0; j <= 3000; j++) {
			dp[i][j] = -1;
		}
	}
	dp[0][0] = 1;
	cin >> a >> b >> c >> d >> e >> f;
	int maxi=0, maxj=0;
	for (i = 0; i <= f; i++) {
		for (j = 0; j <= f; j++) {
			if ((100+e) * j <= i * e) {
				if ((maxi == 0) && (maxj == 0)) {
					if (DP(i, j) == 1) {
						maxi = i; maxj = j;
					}
				}
				else {
					if (maxj * i < maxi * j) {
						if (DP(i, j) == 1) {
							maxi = i; maxj = j;
						}
					}
				}
			}
		}
	}
	//cout << dp[110][10];
	cout << maxi << ' ' << maxj << endl;
	return 0;

}
int DP(int x, int y) {
	if ((x < 0) || (y < 0)) { return 0; }
	if ((x == y) && (x > 0)) {
		dp[x][y] = 0;
		return 0;
	}
	if (dp[x][y] >= 0) {
		return dp[x][y];
	}
	else {
		if ((DP(x - 100 * a, y) == 1) || (DP(x - 100 * b, y) == 1) || (DP(x-c, y - c) == 1) || (DP(x-d, y - d) == 1)) {
			dp[x][y] = 1;
			return 1;
		}
		else {
			dp[x][y] = 0;
			return 0;
		}
	}
}