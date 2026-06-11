#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define mp make_pair
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define all(v) v.begin(),v.end()

const int maxn = 2e3 + 100;
const ll inf = 2e18, mod = 1e9 + 7;

int n, k;
ll fact[maxn * maxn], invfact[maxn * maxn], dp[maxn][maxn];

ll powmod(ll a, ll b)
{
	if (b == 1)
		return a;
	ll tmp = powmod(a, b / 2);
	tmp = tmp * tmp % mod;
	if (b & 1)
		tmp = tmp * a % mod;
	return tmp;
}

ll comb(int n, int r)
{
	return (fact[n] * (invfact[r] * invfact[n - r] % mod) % mod);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	fact[0] = invfact[0] = 1;
	for (int i = 1; i < maxn * maxn; i++)
	{
		fact[i] = fact[i - 1] * i % mod;
		invfact[i] = powmod(fact[i], mod - 2);
	}

	cin >> n >> k;
	if (k == 1)
	{
		cout << 1 << endl;
		return 0;
	}
	dp[1][0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= i; j++)
		{
			if (i < n)
				dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % mod;
			if (j < i)
				dp[i][j + 1] = (dp[i][j + 1] + dp[i][j] * comb(n * k - i - j * (k - 1) - 1, k - 2)) % mod;
		}
	cout << dp[n][n] * fact[n] % mod << endl;
}

