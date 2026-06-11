#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#define LL long long
using namespace std;

LL dp[55][55][2550];
LL x, ans;

int main()
{
	int n, aver;
	cin >> n >> aver;
	dp[0][0][0] = 1;
	
	for(int i = 1; i <= n; i++)
	{
		cin >> x;
		for(int j = 0; j <= i; j++)
			for(int k = 0; k <= 2500; k++)
			{
				dp[i][j][k] += dp[i - 1][j][k];
				if(k >= x && j >= 1) dp[i][j][k] += dp[i - 1][j - 1][k - x];
			}
	}
	
	for(int i = 1; i <= n; i++)
		ans += dp[n][i][i * aver];
	cout << ans << endl;
		
	return 0;
}