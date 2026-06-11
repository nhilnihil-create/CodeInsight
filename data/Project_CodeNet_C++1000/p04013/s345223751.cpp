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

LL dp[500][2550];
LL x, ans;

int main()
{
	int n, aver;
	cin >> n >> aver;
	dp[0][0] = 1;
	
	for(int i = 1; i <= n; i++)
	{
		cin >> x;
		for(int j = i; j > 0; j--)
			for(int k = x; k <= 2550; k++)
				dp[j][k] += dp[j - 1][k - x];//k要大于等于x
	}
	
	for(int i = 1; i <= n; i++)
		ans += dp[i][i * aver];
	cout << ans << endl;
		
	return 0;
}