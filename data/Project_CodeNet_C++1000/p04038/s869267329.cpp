#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <math.h>
using namespace std;

typedef long long ll;
const int MAXN = 2000 + 10;
const int M = 1e7 + 10;
const int Mod = 1e9 + 7;
int N, K;
int fac[M], inv[M], ifc[M];
int f[MAXN];

inline void init(int n) {
	register int i;
	for( fac[0] = i = 1; i <= n; ++i ) fac[i] = 1ll * fac[i - 1] * i % Mod;
	for( inv[1] = 1, i = 2; i <= n; ++i ) inv[i] = 1ll * (Mod - Mod / i) * inv[Mod % i] % Mod;
	for( ifc[0] = ifc[1] = 1, i = 2; i <= n; ++i ) ifc[i] = 1ll * ifc[i - 1] * inv[i] % Mod;
}

inline int C(int n, int k) {
	if( n < 0 || k < 0 || n < k ) return 0;
	return 1ll * fac[n] * ifc[k] % Mod * ifc[n - k] % Mod;
}

int main() {
	register int i, j;
	scanf( "%d%d", &N, &K ); --K;
	if(!K) return 0 * puts("1");
	init(10000000); f[0] = 1;
	for( i = 1; i <= N; ++i )
		for( j = 1; j <= i; ++j )
			f[j] = (f[j] + 1ll * (N - j + 1) * C(N * K + N - i - (j - 1) * K - 1, K - 1) % Mod * f[j - 1]) % Mod;
	printf( "%d\n", f[N] );
	return 0;
}