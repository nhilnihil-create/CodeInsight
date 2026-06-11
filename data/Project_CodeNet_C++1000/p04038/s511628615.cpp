#include <iostream>
#define llint long long
#define mod 1000000007

using namespace std;

llint n, k;
llint dp[2005][2005];

const int FACT_MAX = 4000005;
llint fact[FACT_MAX], fact_inv[FACT_MAX];

llint modpow(llint a, llint n)
{
	if(n == 0) return 1;
	if(n % 2){
		return ((a%mod) * (modpow(a, n-1)%mod)) % mod;
	}
	else{
		return modpow((a*a)%mod, n/2) % mod;
	}
}

void make_fact()
{
	llint val = 1;
	fact[0] = 1;
	for(int i = 1; i < FACT_MAX; i++){
		val *= i;
		val %= mod;
		fact[i] = val;
	}
	fact_inv[FACT_MAX-1] = modpow(fact[FACT_MAX-1], mod-2);
	for(int i = FACT_MAX-2; i >= 0; i--){
		fact_inv[i] = fact_inv[i+1] * (i+1) % mod;
	}
}

llint comb(llint n, llint k)
{
	llint ret = 1;
	ret *= fact[n];
	ret *= fact_inv[k], ret %= mod;
	ret *= fact_inv[n-k], ret %= mod;
	return ret;
}

int main(void)
{
	cin >> n >> k;
	make_fact();
	if(k == 1){
		cout << 1 << endl;
		return 0;
	}
	
	dp[1][1] = 1;
	for(int i = 1; i < n; i++){
		llint sum = 0;
		for(int j = i; j >= 0; j--){
			sum += dp[i][j], sum %= mod;
			dp[i+1][j+1] = sum * comb(i*k-j+k-2, k-2) % mod, dp[i+1][j+1] %= mod;
		}
	}
	
	llint ans = 0;
	for(int i = 1; i <= n; i++) ans += dp[n][i], ans %= mod;
	ans *= fact[n], ans %= mod;
	cout << ans << endl;

	
	return 0;
}