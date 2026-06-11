#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;
const int N = 2048, M = 5e6 + 10, Mod = 1e9 + 7;

inline void Read(int &x)
{
	x = 0; register char cc = '\0'; int fff = 1;
	for (; cc < '0' || cc > '9'; cc = getchar())
		if (cc == '-') fff = -1;
	for (; cc >= '0' && cc <= '9'; cc = getchar())
		x = (x << 1) + (x << 3) + (cc & 15);
	x *= fff;
}

int n, K, num, f[N][N], fac[M + 10], ifac[M + 10];

inline int Pow(int x, int y) {
	int sum = 1;
	while (y) {
		if (y & 1) sum = (LL)sum * x % Mod;
		x = (LL)x * x % Mod; y >>= 1;
	}
	return sum;
}

inline int C(int x, int y) {
	if (x < y || y < 0) return 0;
	return (LL)fac[x] * ifac[x - y] % Mod * ifac[y] % Mod;
}

int main()
{
	fac[0] = ifac[0] = 1;
	for (int i = 1; i <= M; ++i) fac[i] = (LL)fac[i - 1] * i % Mod;
	ifac[M] = Pow(fac[M], Mod - 2);
	for (int i = M - 1; i >= 1; --i) ifac[i] = (LL)ifac[i + 1] * (i + 1) % Mod;
	
	Read(n), Read(K);
	if (K == 1) {
		printf("1\n"); /*!!!*/
		return 0;
	}
	num = (LL)n * K;
	
	f[0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= i; ++j) {
			if (i > j) f[i][j] = f[i - 1][j];
			if (j > 0) f[i][j] = (f[i][j] + (LL)f[i][j - 1] * (n - (j - 1)) % Mod * C(num - (K - 1) * (j - 1) - i - 1,K - 2) % Mod) % Mod;
		}
	}
	
	printf("%d\n", f[n][n]);
	
	return 0;
}
