#include <algorithm>
#include <cstring>
#include <cstdio>
long long dp[100005][3];
int arr[100005];
char op[100005]; 
int main()
{
	// freopen("ARC066-E.in", "r", stdin); 
	int n; 
	scanf("%d%d", &n, arr); 
	for (int i = 1; i < n; i++)
		scanf("%*c%c%d", op + i, arr + i); 
	memset(dp, -0x3f, sizeof(dp)); 
	dp[0][0] = arr[0]; 
	for (int i = 1; i < n; i++)
	{
		if (op[i] == '+')
		{
			dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1]) + arr[i]; 
			dp[i][1] = dp[i - 1][1] - arr[i];
			dp[i][2] = dp[i - 1][2] + arr[i];
		}
		else
		{
			dp[i][1] = std::max(dp[i - 1][0], dp[i - 1][1]) - arr[i];
			dp[i][2] = std::max(dp[i - 1][1], dp[i - 1][2]) + arr[i];
		}
	}
	printf("%lld\n", std::max(dp[n - 1][0], std::max(dp[n - 1][1], dp[n - 1][2])));
	return 0; 
}
