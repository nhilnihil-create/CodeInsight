#include <cstdio>

typedef long long LL;
const int Mod = 1000000007;
const int MN = 2005, MS = 4000005;

inline int qPow(int b, int e) {
	int a = 1;
	for (; e; e >>= 1, b = (LL)b * b % Mod)
		if (e & 1) a = (LL)a * b % Mod;
	return a;
}

int Fac[MS], iFac[MS];
inline void Init(int N) {
	Fac[0] = 1;
	for (int i = 1; i <= N; ++i) Fac[i] = (LL)Fac[i - 1] * i % Mod;
	iFac[N] = qPow(Fac[N], Mod - 2);
	for (int i = N; i >= 1; --i) iFac[i - 1] = (LL)iFac[i] * i % Mod;
}
inline int Binom(int N, int M) {
	return (LL)Fac[N] * iFac[M] % Mod * iFac[N - M] % Mod;
}

int N, K;
int f[MN][MN];

int main() {
	scanf("%d%d", &N, &K);
	if (K == 1 || N == 1) return puts("1"), 0;
	Init(N * K);
	f[0][0] = 1;
	for (int j = 1; j <= N; ++j) f[0][j] = (LL)f[0][j - 1] * Binom(j * (K - 1) - 1, K - 2) % Mod;
	for (int i = 1; i <= N; ++i) {
		f[i][i] = f[i - 1][i];
		for (int j = i + 1; j <= N; ++j)
			f[i][j] = (f[i - 1][j] + (LL)f[i][j - 1] * Binom(i + j * (K - 1) - 1, K - 2)) % Mod;
	}
	printf("%lld\n", (LL)f[N][N] * Fac[N] % Mod);
	return 0;
}