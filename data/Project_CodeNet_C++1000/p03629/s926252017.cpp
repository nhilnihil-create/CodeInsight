#include<bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(); cin.tie(0); cout.tie(0);
#define pb push_back
#define ll long long
#define fi first
#define se second
#define maxn 200005

const int mod = 1e9+7 ;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;

int dp[maxn][150], pos[maxn][150];

signed main()
{
//	freopen(".inp","r",stdin);
//	freopen(".out","w",stdout);
	fastio;
	string str;	cin >> str;
	int n = str.length();
	for (int i = 0; i <= maxn; i++)
		for (int j = 0; j <= 200; j++)	dp[i][j] = mod;
	dp[n][str[n-1]] = 2;
	for (int j = 'a'; j <= 'z'; j++)
	{
		pos[n][j] = n+1;
		if (dp[n][j] == mod)	dp[n][j] = 1;
		dp[n+1][j] = 1;
	}
	pos[n][str[n-1]] = n;
	for (int i = n-1; i > 0; i--)
	{
		pos[i][str[i-1]] = i;
		for (int j = 'a'; j <= 'z'; j++)
		{
			dp[i][str[i-1]] = min(dp[i+1][j] + 1, dp[i][str[i-1]]);
		}
		for (int j = 'a'; j <= 'z'; j++)
		{
			if (j != str[i-1])
			{
				pos[i][j] = pos[i+1][j];
				dp[i][j] = dp[i+1][j];
			}
		}
	}
	int ans = mod;
	for (int i = 'a'; i <= 'z'; i++)
	{
		ans = min(ans, dp[1][i]);
	}
	int run = 1;
	while (run <= n)
	{
		for (int i = 'a'; i <= 'z'; i++)
		{
			if (dp[run][i] == ans)
			{
				ans--;
				cout << (char)i;
				run = pos[run][i];
				break;
			}
		}
		run++;
	}
}
