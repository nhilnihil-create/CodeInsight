#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e15;
typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pii;

void faster()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const ll MAXN = 1e6 + 10;
const ll N = 4000 + 10;
const ll MN = 200 + 10;
const ll mod = 1e6;

ll dp[N][N], b[N], a[N];

int main()
{
	faster();
	ll n , x;
	cin >> n >> x;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		dp[i][i] = a[i];
		for (int j = i + 1; j < n; j++)
		{
			dp[i][j] = min(dp[i][j - 1], a[j]);
		}
	}
	ll ans = inf;
	for (int k = 0; k <= n; k++)
	{
		ll t = 0;
		for (int i = 0; i < n; i++)
		{
			if(i >= k)
				t += dp[i - k][i];
			else
			{
				t += min(dp[0][i], dp[n - k + i][n - 1]);
			}
		}
		t += k * x;
		ans = min(t, ans);
	}
	cout << ans << endl;
}