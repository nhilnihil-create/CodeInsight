#include <cstdio>
#define MOD 1000000007
#define sqr(x) ((ll)(x) * (x))
typedef long long ll; 
ll dp[1000005], sum; 
int main()
{
	// freopen("ARC071-F.in", "r", stdin); 
	int n; 
	scanf("%d", &n); 
	dp[1] = n; 
	dp[2] = sqr(n) % MOD; 
	for (int i = 3; i <= n; i++)
	{
		dp[i] = (dp[i - 1] + sqr(n - 1) + sum + n - i + 2) % MOD; 
		(sum += dp[i - 2]) %= MOD; 
	}
	printf("%lld\n", dp[n]);
	return 0;
}
