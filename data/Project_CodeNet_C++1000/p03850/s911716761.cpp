#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

long long dp[100050][3];
char sign[100050];
int val[100050];
int sgn[100050];

int main()
{
	int n; scanf("%d",&n);
	for(int i = 1;i <= n; ++ i)
	{
		scanf(" %d",&val[i]);
		if(i != n) scanf(" %c",&sign[i + 1]),sgn[i + 1] = sign[i + 1] == '-' ? -1 : 1;
	}
	sgn[0] = 1;
	memset(dp,-0x3f3f3f3f,sizeof(dp));
	dp[1][0] = val[1];
	for(int i = 2;i <= n; ++ i)
	{
		for(int j = 0;j <= 2; ++ j)
		{
			if(sgn[i] == -1)
			{
				if(j)
				{
					if(j == 2) 
						dp[i][j] = max(dp[i][j],dp[i - 1][j - 1] + val[i]);
					else
						dp[i][j] = max(dp[i][j],dp[i - 1][j - 1] - val[i]);
				}
				if(j % 2 == 0) dp[i][j] = max(dp[i][j],dp[i - 1][j] - val[i]);
				else dp[i][j] = max(dp[i][j],dp[i - 1][j] + val[i]);
				if(j != 2)
				{
					if(j == 1)
						dp[i][j] = max(dp[i][j],dp[i - 1][j + 1] - val[i]);
					else
						dp[i][j] = max(dp[i][j],dp[i - 1][j + 1] + val[i]);
				}
			}
			else
			{
				if(j % 2 == 0) dp[i][j] = max(dp[i][j],dp[i - 1][j] + val[i]);
				else dp[i][j] = max(dp[i][j],dp[i - 1][j] - val[i]);
				if(j != 2)
				{
					if(j == 1)
						dp[i][j] = max(dp[i][j],dp[i - 1][j + 1] + val[i]);
					else
						dp[i][j] = max(dp[i][j],dp[i - 1][j + 1] - val[i]);
				}
			}
		}
	}
	printf("%lld\n",max(dp[n][0],dp[n][1]));
}