#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll mod = 1000000007;
ll dp[2010101], rui[2010101];
int main()
{
	ll num;
	scanf("%lld", &num);
	dp[0] = rui[0] = 1;
	ll ans = 0;
	for (int i = 0; i <= num; i++)
	{
		if (i <= num - 2)ans = (ans + dp[i] * (num - 1) % mod*(num - 1) + dp[i] * (i + 1)) % mod;
		else if (i == num - 1)ans = (ans + dp[i] * (num - 1)) % mod;
		else ans = (ans + dp[i]) % mod;
		dp[i + 1] = ((i >= 2) ? (rui[i - 2] + dp[i]) % mod : dp[i]);
		rui[i + 1] = (rui[i] + dp[i + 1]) % mod;
		//printf("%d %lld %lld\n", i, dp[i], ans);
	}
	printf("%lld\n", ans);
}