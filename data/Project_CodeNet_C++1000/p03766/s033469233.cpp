#include <bits/stdc++.h>

#define F first
#define S second
#define pii pair<int, int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e6 + 10, mod = 1e9 + 7;

int dp[N], ps[N];

int main()
{
	int n, sum; cin >> n;
	dp[1] = n;
	dp[2] = (ll)n * n % mod;
	sum = (dp[1] + dp[2]) % mod;

	for (int i=3; i<=n; i++)
	{
		dp[i] = (((ll)sum - dp[i - 2] + mod) + (ll)(n - 1) * (n - 1)) % mod;
		dp[i] += (n - i + 2), dp[i] %= mod;
		sum += dp[i], sum %= mod;
	}
	cout << dp[n] << endl;
}
