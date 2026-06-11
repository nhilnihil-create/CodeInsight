#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int n, dp[1000007], sum;
int main()
{
	cin >> n;
	dp[n] = n;
	dp[n - 1] = 1LL * n * n % mod;
	for (int i = n - 2; i >= 1; i--)
	{
		sum = (sum + dp[i + 3]) % mod;
		dp[i] = (sum + 1LL * (n - 1) * (n - 1) % mod + dp[i + 1] + i + 1) % mod;
	}
	cout << dp[1] << endl;
	return 0;
}