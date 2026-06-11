#include<bits/stdc++.h>
using namespace std;
#define int unsigned
#define fastio ios::sync_with_stdio(); cin.tie(0); cout.tie(0);
#define pb push_back
#define ll long long
#define fi first
#define se second
#define maxn 5001
 
const int mod = 1e9+7 ;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
 
ll dp[maxn][maxn];
 
signed main()
{
	fastio;
	int n;	cin >> n;
	string str;	cin >> str;
	int m = str.length();
	if(n == m) {
		cout << 1; return 0;
	}
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0 && i == 1)
			{
				dp[i][j] = 1;
			}
			else if (j == 0 && i > 1)
			{
				dp[i][j] = (dp[i-1][j] + (2*dp[i-1][1])%mod) % mod;
			}
			else
			{
				dp[i][j] = ((2*dp[i-1][j+1])%mod + dp[i-1][j-1]) % mod;
			}
		}
	}
	cout << dp[n][m];
}