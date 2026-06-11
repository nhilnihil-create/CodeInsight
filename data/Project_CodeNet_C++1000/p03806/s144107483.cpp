#include <iostream>
using namespace std;
#define myfill(a, val, type) fill((type *)a, (type *)a+sizeof(a)/sizeof(type), val)
const int INF = 1001001001;

int main() {
	int n, m_a, m_b;
	cin >> n >> m_a >> m_b;
	const int MAX = 402;
	int dp[MAX][MAX]; myfill(dp, INF, int);
	dp[0][0] = 0;
	for (int k = 1; k <= n; k++) {
		int a, b, c;
		cin >> a >> b >> c;
		for (int i = MAX-1; i >= 0; i--) {
			for (int j = MAX-1; j >= 0; j--) {
				if (i-a >= 0 && j-b >= 0) {
					dp[i][j] = min(dp[i][j], c + dp[i-a][j-b]);
				}
			}
		}
	}
	int ans = INF;
	for (int i = 1; i*m_a < MAX && i*m_b < MAX; i++) {
		ans = min(ans, dp[i*m_a][i*m_b]);
	}
	if (ans == INF) ans = -1;
	cout << ans << endl;
	return 0;
}