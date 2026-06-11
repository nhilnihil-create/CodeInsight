#include <cstdio>

const int MAXN = 2000, MAXL = MAXN * MAXN, MOD = 1e9 + 7;
int n, K, fac[MAXL + 5], ifac[MAXL + 5], f[MAXN + 5][MAXN + 5];

inline void addeq ( int& a, const int b ) { if ( ( a += b ) >= MOD ) a -= MOD; }

inline int qkpow ( int a, int b ) {
	int ret = 1;
	for ( ; b; a = 1ll * a * a % MOD, b >>= 1 ) ret = 1ll * ret * ( b & 1 ? a : 1 ) % MOD;
	return ret;
}

inline void init ( const int n ) {
	fac[0] = 1;
	for ( int i = 1; i <= n; ++ i ) fac[i] = 1ll * i * fac[i - 1] % MOD;
	ifac[n] = qkpow ( fac[n], MOD - 2 );
	for ( int i = n - 1; ~ i; -- i ) ifac[i] = ( i + 1ll ) * ifac[i + 1] % MOD;
}

inline int C ( const int n, const int m ) {
	return n < m ? 0 : 1ll * fac[n] * ifac[m] % MOD * ifac[n - m] % MOD;
}

int main () {
	scanf ( "%d %d", &n, &K );
	if ( K == 1 ) return puts ( "1" ), 0;
	init ( n * K ), f[0][0] = 1;
	for ( int i = 1; i <= n; ++ i ) {
		for ( int j = 0; j <= i; ++ j ) {
			int& cur = f[i][j];
			if ( i ^ j ) addeq ( cur, f[i - 1][j] );
			if ( j ) addeq ( cur, 1ll * f[i][j - 1]
				* C ( n * K - i - ( j - 1 ) * ( K - 1 ) - 1, K - 2 ) % MOD );
		}
	}
	printf ( "%d\n", int ( 1ll * f[n][n] * fac[n] % MOD ) );
	return 0;
}