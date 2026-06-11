#include <iostream>
#include <cstdio>
#include <cstring>

#define MOD 1000000007

using namespace std;

typedef long long LL;

const int MAXN = 2000 + 10;
const int MAXM = MAXN * MAXN;

int N, K;

LL fact[MAXM]= {0}, invfact[MAXM]= {0};
void init () {
	fact[0] = fact[1] = invfact[0] = invfact[1] = 1;
	for (int i = 2; i <= N * K; i ++) {
		fact[i] = fact[i - 1] * i % MOD;
		invfact[i] = (MOD - MOD / i) * invfact[MOD % i] % MOD;
	}
	for (int i = 1; i <= N * K; i ++)
		invfact[i] = invfact[i - 1] * invfact[i] % MOD;
}
inline LL C (int n, int m) {
	if (n < 0) return 0;
	if (m == 0) return 1;
	return fact[n] * invfact[m] % MOD * invfact[n - m] % MOD;
}

LL f[MAXN][MAXN]= {0};

int main () {
	scanf ("%d%d", & N, & K);
	if (K == 1) {
		puts ("1");
		return 0;
	}
	init ();
	f[0][0] = 1;
	for (int i = 1; i <= N; i ++)
		for (int j = 0; j <= i; j ++) {
			LL delta = f[i][j - 1] * (N - j + 1) % MOD * C (N * K - i - (K - 1) * (j - 1) - 1, K - 2) % MOD;
			if (j == 0) delta = 0;
			f[i][j] = (f[i][j] + f[i - 1][j] + delta) % MOD;
		}
	cout << f[N][N] << endl;

	return 0;
}

/*
2 2
*/

/*
3 1
*/

/*
2 3
*/

/*
2000 2000
*/