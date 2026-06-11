#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{

	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt" , "r" , stdin);
// 	freopen("output.txt" , "w" , stdout);
// #endif

	ll n, m, r;
	cin >> n >> m >> r;
	ll rp[r];
	for (ll i = 0; i < r; i++)
		cin >> rp[i];
	ll dp[n + 1][n + 1] = {0};
	for (ll i = 1; i <= n; i++)
	{
		for (ll j = 1; j <= n; j++)
		{
			if (i != j)
				dp[i][j] = INT_MAX;
		}
	}
	for (ll i = 1; i <= m; i++)
	{
		ll a, b, c;
		cin >> a >> b >> c;
		if (dp[a][b] > c)
		{
			dp[a][b] = c;
			dp[b][a] = c;
		}
	}

	for (ll k = 1; k <= n; k++)
	{
		for (ll i = 1; i <= n; i++)
		{
			for (ll j = 1; j <= n; j++)
			{
				if (dp[i][j] > dp[i][k] + dp[k][j])
					dp[i][j] = dp[i][k] + dp[k][j];
			}
		}
	}

	ll mx = INT_MAX;
	sort(rp, rp + r);
	do
	{
		ll sum = 0;
		for (ll i = 0; i < r - 1; i++)
			sum += dp[rp[i]][rp[i + 1]];
		mx = min(sum, mx);

	} while (next_permutation(rp, rp + r));

	cout << mx << endl;
}
