#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll dp[200000][3];
int main()
{
	int num;
	scanf("%d", &num);
	ll now = 0;
	for (int i = 0; i < 200000; i++)dp[i][0] = dp[i][1] = dp[i][2] = -1000000000000000000LL;
	int zt;
	scanf("%d", &zt);
	dp[0][0] = zt;
	for (int i = 1; i < num; i++)
	{
		char za;
		int zb;
		scanf(" %c%d", &za, &zb);
		if (za == '+')
		{
			dp[i][0] = max(dp[i][0], dp[i - 1][0] + zb);
			dp[i][1] = max(dp[i][1], dp[i - 1][1] - zb);
			dp[i][2] = max(dp[i][2], dp[i - 1][2] + zb);
			dp[i][0] = max(dp[i][0], dp[i - 1][1] - zb);
			//dp[i][0] = max(dp[i][0], dp[i - 1][2] + zb);
			dp[i][1] = max(dp[i][1], dp[i - 1][2] + zb);
		}
		else
		{
			dp[i][0] = max(dp[i][0], dp[i - 1][0] - zb);
			dp[i][1] = max(dp[i][1], dp[i - 1][1] + zb);
			dp[i][2] = max(dp[i][2], dp[i - 1][2] - zb);
			dp[i][1] = max(dp[i][1], dp[i - 1][0] - zb);
			dp[i][2] = max(dp[i][2], dp[i - 1][1] + zb);
			//dp[i][2] = max(dp[i][2], dp[i - 1][0] - zb);
			dp[i][0] = max(dp[i][0], dp[i - 1][1] + zb);
			//dp[i][0] = max(dp[i][0], dp[i - 1][2] - zb);
			dp[i][1] = max(dp[i][1], dp[i - 1][2] - zb);
		}
	}
	printf("%lld\n", max(dp[num - 1][0], max(dp[num - 1][1], dp[num - 1][2])));
}