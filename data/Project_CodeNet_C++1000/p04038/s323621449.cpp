#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <vector>
#include <complex>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;
const long long mod = 1e9 + 7;
const int maxn = 2005;
long long ksm(const long long &a, const long long &k)
{
	long long ans = 1;
	for(long long x = a % mod, asd = k; asd; asd >>= 1, (x *= x) %= mod)
		if(asd & 1)
			(ans *= x) %= mod;
	return ans;
}
long long fac[maxn * maxn], invfac[maxn * maxn];
long long calc(const int &n, const int &k)
{
	if(k < 0 || n < k)
		return 0;
	return fac[n] * invfac[k] % mod * invfac[n - k] % mod;
}
long long dp[maxn][maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	if(n * k < n + k)
	{
		cout << 1 << endl;
		return 0;
	}
	fac[0] = 1;
	for(int i = 1; i <= n * k; i ++)
		fac[i] = fac[i - 1] * i % mod;
	invfac[n * k] = ksm(fac[n * k], mod - 2);
	for(int i = n * k - 1; i >= 0; i --)
		invfac[i] = invfac[i + 1] * (i + 1) % mod;
	dp[0][0] = 1;
	for(int i = 1; i <= n; i ++)
		dp[0][i] = dp[0][i - 1] * calc(i * (k - 1) - 1, k - 2) % mod;
	for(int i = 1; i <= n; i ++)
		for(int j = i; j <= n; j ++)
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1] * calc(j * (k - 1) + i - 1, k - 2)) % mod;
	cout << dp[n][n] * fac[n] % mod << endl;
	
	return 0;
}