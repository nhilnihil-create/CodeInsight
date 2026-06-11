#include <bits/stdc++.h>
using namespace std;
long long fac[4000010], inv[4000010], finv[4000010]; 
long long MOD = 1000000007; 
void COMinit(){
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for(int i = 2; i < 4000005; i++) {
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}
long long COM(int n, int k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
int main(){
	int N, K; cin >> N >> K; 
	if(K == 1){
		cout << 1 << "\n"; return 0; 
	}
	COMinit(); 
	long long dp[2005][2005] = {}; // dp[i以上の数を並べ終わり][そこまでに0がj個含まれている]
	long long DP[2005][2005] = {}; // その累積和
	dp[N][0] = 1;
	DP[N][0] = 1; DP[N][1] = 1;
	for(int i = N-1; i >= 1; i--){	
		for(int j = 0; j <= N-i; j++){
			dp[i][j] = DP[i+1][j] * COM((N-i)*(K-1)+j+K-2, K-2) % MOD; 
		}
		DP[i][0] = dp[i][0]; 
		for(int j = 1; j <= N+1-i; j++){
			DP[i][j] = DP[i][j-1] + dp[i][j]; 
			if(DP[i][j] >= MOD) DP[i][j] -= MOD; 
		}
	}
	cout << (DP[1][N] * fac[N]) % MOD << "\n"; 
}