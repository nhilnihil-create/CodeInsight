#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 4050005
#define m 2005
#define mod 1000000007
#define ll long long
using namespace std;
int n, k;
ll jc[maxn], bjc[maxn];
ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
ll c(int a, int b) {
	if (a < b || b < 0) return 0;
	return 1ll * jc[a] * bjc[b] % mod * bjc[a - b] % mod;
}
ll dp[m][m];
int main() {
	bjc[0] = jc[0] = 1;
	for (int i = 1; i < maxn; i++)
		jc[i] = jc[i - 1] * i % mod;
	bjc[maxn - 1] = ksm(jc[maxn - 1], mod - 2);
	for (int i = maxn - 2; i >= 0; i--)
		bjc[i] = bjc[i + 1] * (i + 1) % mod;
//	cout << bjc[0] << endl;
	cin >> n >> k;
	if (k == 1) {
		cout << 1 << endl;
		return 0;
	}
//	cout << "!@#" << endl;
	k--;
	ll ans = jc[n];
	for (int i = n; i >= 0; i--)
		for (int j = i; j >= 0; j--) {
			if (j == n) dp[i][j] = 1;
			else {
				dp[i][j] = dp[i][j + 1];
				ll nx = dp[i + 1][j];
				int tot = k * i + j + (k - 1);
				nx = nx * c(tot, k - 1) % mod;
				dp[i][j] = (dp[i][j] + nx) % mod;
			}
	//		cout << i << ' ' << j << ' ' << dp[i][j] << endl;
		}
	ans = ans * dp[0][0] % mod;
	cout << ans << endl;
	return 0;
}