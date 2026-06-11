#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const double pi = acos(-1);
const int maxn = 2e6 + 10;
const double eps = 1e-8;
const ll mod = 1e9 + 7;
const ull base = 131;
const ull mod1 = 1e9 + 9;
const ull mod2 = 1610612741;

ll dp[100][3000];

int main()
{
	int n, a;
	scanf("%d%d", &n, &a);
	dp[0][0] = 1;
	for (int i = 1; i <= n; ++i)
	{
		ll x;
		scanf("%lld", &x);
		for (int j = i; j > 0; --j)
			for (int k = a*n; k >= x; --k)
				dp[j][k] += dp[j-1][k-x];
	}
	ll ans = 0;
	for (int i = 1; i <= n; ++i)
		ans += dp[i][i*a];
	printf("%lld\n", ans);
	return 0;
}