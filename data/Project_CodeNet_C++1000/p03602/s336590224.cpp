#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
ll dp[310][310];
ll map[310][310];
ll check[310][310];
int main()
{
	ll n;
	scanf("%lld", &n);
	ll dap = 0;
	for (int i = 0; i < n; i++)
	{
		for (int y = 0; y < n; y++)
		{
			scanf("%lld", &map[i][y]);
			dp[i][y] = map[i][y];
		}
	}

	for (int z = 0; z < n; z++) 
	{
		for (int i = 0; i < n; i++)
		{
			for (int y = 0; y < n; y++)
			{
				dp[i][y] = min(dp[i][y], dp[i][z] + dp[z][y]);
				if (i!=z&&y!=z&&dp[i][y] == dp[i][z] + dp[z][y])
					check[i][y] = 1;
			}
		}
	}
	for (int i = 0; i < n; i++)
		for (int y = 0; y < n; y++)
			if (!check[i][y])
				dap += dp[i][y];
	for (int i = 0; i < n; i++)
	{
		for (int y = 0; y < n; y++)
		{
			if (dp[i][y] != map[i][y])
			{
				puts("-1");
				return 0;
			}
		}
	}
	printf("%lld", dap/2);
}