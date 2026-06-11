#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

typedef long long ll;
const int MAXN = 1100000;
const int MOD = 1e9 + 7;
ll dp[MAXN], sumv;

int main(){
	ll n; scanf("%lld", &n);
	dp[1] = n; dp[2] = (n * n) % MOD;
	for(int i = 3; i <= n; ++ i){
		sumv += dp[i - 3];
		sumv %= MOD;
		dp[i] += dp[i - 1];
		dp[i] += (n - 1) * (n - 1) % MOD;
		dp[i] += sumv + n - i + 2;
		dp[i] %= MOD;
	}
	printf("%lld\n", dp[n]);
	return 0;
}