#include <bits/stdc++.h>

#define MAXN (1000010)
#define mod (1000000007)
#define ll long long

int n;
ll dp[MAXN], sum;

int main(){
	scanf("%d", &n);
	dp[1] = n;
	dp[2] = (dp[1] + (1ll) * (n - 1) * (n - 1) + (n - 1)) % mod;
	sum = dp[1] + dp[2];
	for(int i = 3; i <= n; ++ i){
		dp[i] = ((sum - dp[i - 2] + (1ll) * (n - 1) * (n - 1) + (n - i + 2)) % mod + mod) % mod;
		sum = (sum + dp[i]) % mod;
	}
	printf("%lld\n", dp[n]);
	return 0;
}