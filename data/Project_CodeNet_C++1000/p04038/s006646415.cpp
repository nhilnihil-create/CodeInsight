#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2005, mod = 1e9+7;

int dp[MAXN][MAXN];
int n, k;

int inv[MAXN*MAXN], fac[MAXN*MAXN], ifac[MAXN*MAXN];

inline int choose(int n, int m)
{
	if (n < m) return 0;
	return (long long)fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}

int dfs(int i, int j)
{
	if (j == 0 && i == 0) return 1;
	if (i < 0 || j < 0) return 0;
	if (dp[i][j] != -1) return dp[i][j];
	dp[i][j] = (dfs(i-1, j)+(long long)dfs(i+1, j-1)*choose((n-j+1)*k-(i+1)-1, k-2))%mod;
	return dp[i][j];
}

int main()
{
	cin >> n >> k;
	if (k == 1) {
		puts("1");
		return 0;
	}
	memset(dp, -1, sizeof dp);
	inv[1] = 1;
	for (int i = 2; i <= n*k; i++) inv[i] = (mod-(long long)mod/i*inv[mod%i]%mod)%mod;
	fac[0] = 1, ifac[0] = 1;
	for (int i = 1; i <= n*k; i++)
		fac[i] = (long long)fac[i-1]*i%mod, ifac[i] = (long long)ifac[i-1]*inv[i]%mod;
	cout << (long long)dfs(0, n)*fac[n]%mod << endl;
	return 0;
}
