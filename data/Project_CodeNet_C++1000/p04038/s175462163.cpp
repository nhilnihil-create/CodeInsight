#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 2000 + 5;
const int N2 = 2000 * 2000 + 10;
const int MOD = 1e9 + 7;
int n, k;
ll dp[MAXN][MAXN], fac[N2], inv[N2];

ll c(int m, int k){
	if( m < k) return 0;
	return fac[m]*inv[k]%MOD*inv[m - k]%MOD;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> k;
	if( k == 1)
		return cout << 1 << endl, 0;
	fac[0] = 1, inv[0] = 1,inv[1] = 1, fac[1] = 1;
	for(int i = 2; i < N2; i++){
		fac[i] = fac[i - 1]*i%MOD;
		inv[i] = (MOD - MOD/i) * inv[MOD % i] % MOD;
	}
	for(int i = 1; i < N2; i ++)
		inv[i] = inv[i] * inv[i - 1] % MOD;
	dp[0][0] = 1;
	for(int i = 1; i <= n; i ++){
		for(int j = i; j>= 0 ;j --){
			dp[i][j] = dp[i][j + 1] % MOD;
			if( j ) dp[i][j] = (dp[i][j] + (dp[i - 1][j - 1] * c(i*k - j - 1, k - 2)) % MOD) % MOD;
			dp[i][j] %= MOD;
		}
	}
	cout << dp[n][0] * fac[n] % MOD << endl;
	return 0;
}