#include <cstdio>
using namespace std;

typedef long long LL;
const int N = 2e3 + 10;
const int M = 4e6 + 10;
const int Mod = 1e9 + 7;
int n, K, fac[M], inv[M], f[N][N];

inline int mls(int x) {return x < 0 ? x + Mod : x;}
inline int pls(int x) {return x >= Mod ? x - Mod : x;}
template <class T> inline void in(T &x) {
	x = 0; int f = 1; char ch = getchar();
	for (; ch<'0' || ch>'9';) {if (ch=='-') f=-1; ch = getchar();}
	for (; ch>='0' && ch<='9';) x = x*10 + ch-'0', ch = getchar();
	x *= f;
}

inline int C(int n, int m) {
	if (n < m || m < 0) return 0;
	return 1LL * fac[n] * inv[m] % Mod * inv[n - m] % Mod;
}

int main() {
	in(n), in(K);
	if (K == 1) {puts("1"); return 0;}
	inv[0] = fac[0] = inv[1] = fac[1] = f[0][0] = 1;
	for (int i = 2; i < M; ++i) inv[i] = 1LL * (Mod - Mod/i) * inv[Mod%i] % Mod;
	for (int i = 2; i < M; ++i) inv[i] = 1LL * inv[i - 1] * inv[i] % Mod;
	for (int i = 2; i < M; ++i) fac[i] = 1LL * fac[i - 1] * i % Mod;
	for (int i = 1; i <= n; ++i)
		for (int j = i; ~j; --j) {
			f[i][j] = f[i][j + 1];
			if (j) f[i][j] = pls(f[i][j] + 1LL * f[i-1][j-1] * C(i*K-j-1, K-2) % Mod);
		}
	printf("%lld\n", 1LL * f[n][0] * fac[n] % Mod);
	return 0;
}