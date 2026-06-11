#include<bits/stdc++.h>
using namespace std;
int n;
long long dp[100007][3];
int read()
{
	int num = 0, f = 1;
	char c = getchar();
	while ((c < '0' || c>'9') && c != '-')c = getchar();
	if (c == '-')f = -1, c = getchar();
	while (c < '0' || c>'9')c = getchar();
	while (c >= '0' && c <= '9')num = num * 10 + c - '0', c = getchar();
	return num * f;
}
int main()
{
	n = read();
	dp[0][0] = 0, dp[0][1] = dp[0][2] = -1e18;
	for (int i = 1; i <= n; i++)
	{
		int v = read();
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]) + v;
		dp[i][1] = max(dp[i - 1][1], dp[i - 1][2]) - v;
		dp[i][2] = dp[i - 1][2] + v;
		if (v < 0)
		{
			dp[i][2] = max(dp[i][2], dp[i][1]);
			dp[i][1] = max(dp[i][1], dp[i][0]);
		}
	}
	cout << max(dp[n][0], max(dp[n][1], dp[n][2])) << endl;
	return 0;
}