#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
typedef long long ll;
ll mod = 1000000007;
ll dp[5151][5151];
int main()
{
	int num;
	scanf("%d", &num);
	string s;
	cin >> s;
	dp[0][0] = 1;
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j] * 2) % mod;
			dp[i + 1][max(0, j - 1)] = (dp[i + 1][max(0, j - 1)] + dp[i][j]) % mod;
		}
	}
	ll ans = dp[num][s.size()];
	for (int i = 0; i < s.size(); i++)ans = ans*((mod + 1) / 2) % mod;
	printf("%lld\n", ans);
}