#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

const int MOD = 1e9 + 7 , MAXN = 5e6 + 10;
int fac[MAXN] , finv[MAXN];
int f[2020][2020];
int n , k;
void init(){
	fac[0] = finv[0] = fac[1] = finv[1] = 1;
	for(int i = 2 ; i <= 5000000 ; ++ i)
		fac[i] = 1ll * i * fac[i - 1] % MOD;
	for(int i = 2 ; i <= 5000000 ; ++ i)
		finv[i] = MOD - 1ll * (MOD / i) * finv[MOD % i] % MOD;
	for(int i = 1 ; i <= 5000000 ; ++ i)
		finv[i] = 1ll * finv[i - 1] * finv[i] % MOD;
}
int C(int x , int y){
	return 1ll * fac[x] * finv[y] % MOD * finv[x - y] % MOD;
}
int main(){
	cin >> n >> k;
	if(k == 1){
		cout << 1 << endl;
		return 0;
	}
	init();
	f[0][0] = 1;
	for(int i = 1 ; i <= n ; ++ i){
		for(int j = 1 ; j < i ; ++ j)
			f[i - 1][j] = (f[i - 1][j] + f[i - 1][j - 1]) % MOD;
		for(int j = 0 ; j < i ; ++ j)
			f[i][j] = 1ll * f[i - 1][j] * C(i * (k - 1) + j - 1 , k - 2) % MOD;
	}
	int ans = 0;
	for(int i = 0 ; i < n ; ++ i)
		ans = (ans + f[n][i]) % MOD;
	cout << 1ll * ans * fac[n] % MOD << endl;
	return 0;
}