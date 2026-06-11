#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const long long inf = 0x3f3f3f3f3f3f3f3f;
int n;
int a[N], op[N];
long long dp[N][20];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i) {
		if (i) {
			char c[5]; scanf("%s", c);
			op[i] = (c[0] == '-' ? -1 : 1);
		}
		scanf("%d", &a[i]);
	}
	memset(dp, -inf, sizeof(dp));
	dp[0][0] = a[0];
	for (int i = 1; i < n; ++ i) {
		for (int j = 0; j < 20; ++ j) {
			if (j && op[i] < 0) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + (j & 1 ? -1 : 1) * a[i]);
			dp[i][j] = max(dp[i][j], dp[i - 1][j] + (j & 1 ? -op[i] : op[i]) * a[i]);
			if (j < 19) dp[i][j] = max(dp[i][j], dp[i - 1][j + 1] + (j & 1 ? op[i] : -op[i]) * a[i]);
		}
	}
	printf("%lld\n", dp[n - 1][0]);
	return 0;
}