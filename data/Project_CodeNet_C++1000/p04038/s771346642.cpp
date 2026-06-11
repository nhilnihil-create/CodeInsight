#include <bits/stdc++.h>
using namespace std;

const int N = 2005;
const long long mod = 1e9 + 7;

long long mod_pow(long long x, long long n){
	long long ret = 1;
	while (n){
		if (n & 1) ret = ret * x % mod;
		x = x * x % mod;
		n >>= 1;
	}
	return ret;
}

long long p[N * N], inv[N * N];
long long dp[N][N];

long long C(int x, int y){
	if (x < y) return 0;
	return p[x] * inv[y] % mod * inv[x - y] % mod;
}

int main(){
	int n, k;
	scanf("%d %d",&n,&k);
	if (k == 1){
		printf("1\n");
		return 0;
	}
	p[0] = inv[0] = 1;
	for (int i = 1; i <= n * k; i++){
		p[i] = p[i - 1] * i % mod;
		inv[i] = mod_pow(p[i], mod - 2);
	}
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++){
		for (int j = 0; j <= i; j++){
			dp[i][j] += dp[i - 1][j];
			dp[i][j] %= mod;
			if (j){
				dp[i][j] += dp[i][j - 1] * C(n - i + (n - j + 1) * (k - 1) - 1, k - 2) % mod * (n - j + 1) % mod;
				dp[i][j] %= mod;
			}
		}
	}
	printf("%lld\n", dp[n][n]);
	return 0;
} 