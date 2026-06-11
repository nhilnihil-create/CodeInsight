#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define MAX 510000
using namespace std;
typedef long long ll;
const int mod = 998244353;
#define V vector<ll>
#define VV vector<V>
#define VVV vector<VV>

signed main(void)
{
	int N, A, X;
	cin >> N >> A;
	int x[N + 1];

	X = A;
	x[0] = 0;
	for (int i = 1; i <= (N); i++)
	{
		cin >> x[i];
		X = max(x[i], X);
	}
	VVV dp(N + 1, VV(N + 1, V(N * X + 1, 0)));
	dp[0][0][0] = 1;
	for (int j = 0; j <= N; j++)
	{
		for (int k = 0; k <= N; k++)
		{
			for (int s = 0; s <= N * X; s++)
			{
				if (s < x[j] && j >= 1)
					dp[j][k][s] = dp[j - 1][k][s];
				else if (k >= 1 && j >= 1)
					dp[j][k][s] = dp[j - 1][k][s] + dp[j - 1][k - 1][s - x[j]];
			}
		}
	}
	ll ans = 0;
	for(int k = 1; k <= N; k++)
		ans += dp[N][k][k * A];
	cout << ans << endl;
	return 0;
}
