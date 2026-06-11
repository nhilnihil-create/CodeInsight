#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long LL;
int op[N], num[N]; LL dp[N][3]; char s[5];
int main() {
	int n; scanf("%d%d", &n, &num[1]), op[1] = 1;
	for (int i = 2; i <= n; i++) {
		scanf("%s%d", s + 1, &num[i]);
		if (s[1] == '-') op[i] = -1; else op[i] = 1;
	}
	memset(dp, -0x3f, sizeof(dp)), dp[1][0] = num[1];
	for (int i = 2; i <= n; i++) {
		dp[i][1] = dp[i - 1][1] - op[i] * num[i];
		dp[i][0] = dp[i - 1][0] + op[i] * num[i];
		dp[i][2] = dp[i - 1][2] + op[i] * num[i];
		if (op[i - 1] == -1) {
			dp[i][1] = max(dp[i][1], dp[i - 1][0] - op[i] * num[i]);
			dp[i][2] = max(dp[i][2], dp[i - 1][1] + op[i] * num[i]);
		}
		dp[i][1] = max(dp[i][1], dp[i][2]);
		dp[i][0] = max(dp[i][0], dp[i][1]);
	}
	printf("%lld\n", dp[n][0]);
}