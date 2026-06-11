#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;

#define N 1100000
#define P 1000000007

int dp[N], sum[N];
int n;

int main() {
	scanf("%d", &n);
	dp[0] = 1;
	dp[1] = n;
	sum[0] = 1;
	sum[1] = n + 1;
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1];
		dp[i] = (dp[i] + 1LL * (i - 2) * (n - 1)) % P;
		if (i >= 3)
			dp[i] = (dp[i] + sum[i - 3]) % P;
		// for (int j = 2; j <= i - 1; j++)
		// 	dp[i] = (dp[i] + dp[i - j - 1] + (n - 1)) % P;
		dp[i] = (dp[i] + 1LL * (n - i + 1) * n) % P;
		sum[i] = (dp[i] + sum[i - 1]) % P;
	}
	printf("%d\n", dp[n]);
}
