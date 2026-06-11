#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 1000010;
const int inf = 0x0fffffff;
#define LL long long
const long long mod = 1000000007;

LL dp[maxn];
int main()
{
	int n, i, k;
	LL sum, ans;
	cin >> n;
	dp[1] = n;
	dp[2] = (1LL * n * n) % mod;
	//dp[2] = (1LL * (n - 1) * (n - 1)) % mod;
	sum = dp[1] + dp[2];
	sum %= mod;
	for (k = 3; k <= n; k ++)
	{
		dp[k] = (sum + mod - dp[k - 2] + 1LL * (n - 1)* (n - 1) + (n - k + 2) )% mod;
		sum = (sum + dp[k]) % mod; 
		//for (i = k - 3; i > 0; i --)
		//	dp[k] = (dp[k] + dp[i]) % mod;
	}
	//ans = 0;
	//for (k = 1; k <= n; k ++)
	//	ans = (ans + dp[k]) % mod;
	cout << dp[n];
	return 0;
}