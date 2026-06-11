/*vi:se ts=8 tw=8*/
/*@author tangyida*/
#include<bits/stdc++.h>
const int N = 2e3 + 5;
const long long MOD = 1e9 + 7;
int n,k;
long long f[N][N],fac[N * N],inv[N * N];

inline long long _pow(long long a,long long base)
{
	long long ans = 1;
	for(;base;base >>= 1) {
		if(base  & 1) ans = (ans * a) % MOD;
		a = (a * a) % MOD;
	}
	return ans;
}

inline void pre()
{
	fac[0] = 1;
	for(int i = 1;i <= n * k;i++) fac[i] = (fac[i - 1] * i) % MOD;
	inv[n * k] = _pow(fac[n * k],MOD - 2) % MOD;
	for(int i = n * k - 1;i >= 0;i--) inv[i] = (inv[i + 1] * (i + 1)) % MOD;
}

inline long long C(long long n,long long m)
{ 
	if(n == m) return 1;
	return ((fac[n] * inv[m]) % MOD * inv[n - m]) % MOD;
}

int main()
{
	std::cin >> n >> k;
	if(k == 1) std::cout << 1,exit(0);

	pre();
	f[0][0] = 1;
	for(int i = 1;i <= n;i++) for(int j = 0;j <= i;j++) {
		f[i][j] = f[i - 1][j];
		if(!j) continue;
		(f[i][j] = f[i][j] % MOD + (f[i][j - 1] * (n - j + 1)) % MOD * C(n -
			i + (n - j + 1) * (k - 1) - 1,k - 2)) %= MOD;
	}
	std::cout << f[n][n] % MOD;

	return 0;
}
