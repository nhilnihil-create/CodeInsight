/*
输入 N 个数字 A1, A2, . . . , AN，
输入 K。 如果对于所有包含 Ai，
且和大于等于 K 的集合，
去掉 Ai 后和还大于等于 K，
那么 Ai 就是可有可无 的。 
问有多少个元素是可有可无的。
*/
#include <bits/stdc++.h>
using namespace std;
const int maxn = 5005;
int n, k, a[maxn], dp[maxn][maxn];
bool check(int x) {
	memset(dp, 0, sizeof dp);
	if(x == 1) {
		dp[2][0] = 1; dp[2][a[2]] = 1;
		for (int i = 3; i <= n; ++i) 
			for (int j = 0; j <= k; ++j) {
				dp[i][j] = dp[i - 1][j];
				if(j >= a[i]) dp[i][j] |= dp[i - 1][j - a[i]]; 
			}
	}
	else {
		dp[1][0] = dp[1][a[1]] = 1;
		for (int i = 2; i <= n; ++i) {
			if(x == i) {
				for (int j = 0; j <= k; ++j) dp[i][j] = dp[i - 1][j]; continue;
			}
			for (int j = 0; j <= k; ++j) {
				dp[i][j] = dp[i - 1][j];
				if(j >= a[i]) dp[i][j] |= dp[i - 1][j - a[i]];
			}
		}
	}
	for (int i = k - a[x]; i < k; ++i) if(dp[n][i]) return 0;
	return 1; 
}
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]); a[i] = min(a[i], k);
	}
	if(n == 1) {
		if(a[1] >= k) puts("0");
		else puts("1"); return 0;
	}
	sort(a + 1, a + n + 1);
	int l = 1, r = n, ans = 0;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(check(mid)) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	printf("%d\n", ans);
	return 0;
}