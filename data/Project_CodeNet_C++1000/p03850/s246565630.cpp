#include <algorithm>
#include <cstdio>
typedef long long ll; 
const ll INF = 1e18; 
int arr[100005]; 
char op[100005]; 
ll dp[100005][3]; 
int main()
{
	// freopen("ARC066-E.in", "r", stdin); 
	int n;
	scanf("%d", &n); 
	for (int i = 0; i < n - 1; i++)
		scanf("%d %c", arr + i, op + i); 
	scanf("%d", arr + n - 1); 
	dp[0][0] = arr[0]; 
	dp[0][1] = dp[0][2] = -INF; 
	for (int i = 1; i < n; i++)
	{
		if (op[i - 1] == '+')
		{
			dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1]) + arr[i];
			dp[i][1] = dp[i - 1][1] - arr[i]; 
			dp[i][2] = dp[i - 1][2] + arr[i]; 
		}
		else
		{
			dp[i][0] = -INF; 
			dp[i][1] = std::max(dp[i - 1][0], dp[i - 1][1]) - arr[i]; 
			dp[i][2] = std::max(dp[i - 1][1], dp[i - 1][2]) + arr[i]; 
		}
	}
	printf("%lld\n", std::max(dp[n - 1][0], std::max(dp[n - 1][1], dp[n - 1][2])));
	return 0; 
}
