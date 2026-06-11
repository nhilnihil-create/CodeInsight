#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;

const int INF = 1e9;
const int MXG = 410;

int gcd(int x, int y) {
	if (y==0) return x;
	return gcd(y, x%y);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, ma, mb;
	cin >> n >> ma >> mb;
	int a[n][3];
	for (int i=0; i<n; i++)
		for (int j=0; j<3; j++)
			cin >> a[i][j];
	int ans = INF;
	vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(MXG, vector<int>(MXG, INF)));
	dp[0][0][0] = 0;
	
	for (int i=0; i<n; i++) {
		for (int j=0; j<MXG; j++) {
			for (int k=0; k<MXG; k++) {
				if (dp[i][j][k] == INF) continue;
				int ra, rb;
				if (i && j) {
					int g = gcd(j, k);
					ra = j/g;
					rb = k/g;
					if (ra == ma && rb == mb) ans = min(ans, dp[i][j][k]);
				}
//				cout << g << ' ' << i << ' ' << j << ' ' << k << ' ' << dp[i][j][k] << '\n';
				dp[i+1][j][k] = min(dp[i+1][j][k], dp[i][j][k]);
				ra = j+a[i][0]; rb = k+a[i][1];
				dp[i+1][ra][rb] = min(dp[i+1][ra][rb], dp[i][j][k] + a[i][2]);
			}
		}
	}
	for (int j=1; j<MXG; j++) {
		for (int k=1; k<MXG; k++) {
			int g = gcd(j, k);
			int ra = j/g;
			int rb = k/g;
			if (ra == ma && rb == mb) ans = min(ans, dp[n][j][k]);
		}
	}
	if (ans == INF) cout << -1;
	else cout << ans;
}