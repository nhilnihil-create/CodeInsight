#include <bits/stdc++.h>
using namespace std;

const long long INF = 0x3f3f3f3f3f3f3f3f;

int a[100010], op[100010];
char buf[5];
long long dp[100010][3];

int main () {
//	freopen("data.in", "r", stdin);
//	freopen("my.out", "w", stdout);
	int n; scanf("%d", &n);
	scanf("%d", &a[1]), op[1] = 0;
	for (int i = 2; i <= n; i++) {
		scanf("%s", buf);
		op[i] = buf[0] == '-' ? 1 : 0;
		scanf("%d", &a[i]);
	}
	dp[0][0] = 0, dp[0][1] = -INF, dp[0][2] = -INF;
	for (int i = 1; i <= n; i++) {
		dp[i][0] = dp[i][1] = dp[i][2] = -INF;
		// not change
		dp[i][0] = max(dp[i][0], dp[i - 1][0] + (op[i] ? -a[i] : a[i]));
		dp[i][1] = max(dp[i][1], dp[i - 1][1] + (op[i] ? a[i] : -a[i]));
		dp[i][2] = max(dp[i][2], dp[i - 1][2] + (op[i] ? -a[i] : a[i]));
		// change
		if (op[i]) {
			dp[i][1] = max(dp[i][1], dp[i - 1][0] - a[i]);
			dp[i][2] = max(dp[i][2], dp[i - 1][1] + a[i]);
		}
		// flush
		dp[i][1] = max(dp[i][1], dp[i][2]), dp[i][0] = max(dp[i][0], dp[i][1]);
	}
	printf("%lld\n", dp[n][0]);
	return 0;
}
