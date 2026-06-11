#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2222;
const int mod = 1e9 + 7;

int dp[N][N] , n , k , fac[N * N] , inv[N * N];

int Pow(int x , int y = mod - 2) {
	int res = 1;
	for(; y ; y >>= 1 , x = x * x % mod) {
		if(y & 1) {
			res = res * x % mod;
		}
	}
	return res;
}

int C(int x , int y) {
	if(x < y)
	return 0;
	return fac[x] * inv[x - y]  % mod * inv[y] % mod;
}

void Add(int &x , int y) {
	(x += y) %= mod;
}

main(void) {
	scanf("%lld%lld" , &n , &k);
	if(k == 1) {
		puts("1");
		return 0;
	}
	fac[0] = 1;
	for(int i = 1;i <= 4e6;++ i) 
	fac[i] = fac[i - 1] * i % mod;
	inv[4000000] = Pow(fac[4000000]);
	for(int i = 4000000 - 1;i >= 0;-- i) {
		inv[i] = inv[i + 1] * (i + 1) % mod;
	}
	dp[0][0] = 1;
	int All = n * k;
	for(int i = 0;i <= n;++ i) {
		for(int j = n;j >= 0;-- j) 
		if(dp[i][j]){
			if(j) {
				Add(dp[i][j - 1] , dp[i][j] * (n - i + j) % mod * C(All - (i + (i - j) * (k - 1) + 1) , k - 2));
			}
			Add(dp[i + 1][j + 1] , dp[i][j]);
		}
	}
	printf("%lld\n" , dp[n][0]);
}