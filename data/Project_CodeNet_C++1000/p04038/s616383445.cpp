#include <cstring>
#include <cstdio>
#include <algorithm>
#define ll long long
const int MAXN = 2010;
const int MOD = 1000000007;
inline int mul(int x, int y) { return (ll)x * (ll)y % MOD; }
inline int add(int x, int y) { int r = x + y; if(r >= MOD) r -= MOD; return r; }
inline int fpm(int a, int p) {
	int ret = 1, x = a;
	while(p) {
		if(p & 1) ret = mul(ret, x);
		x = mul(x, x);
		p >>= 1;
	}
	return ret;
}
using namespace std;

int N, K, C[MAXN * MAXN], F[MAXN][MAXN], fact[MAXN];

int main() {
	int i, k;
	scanf("%d%d", &N, &K);
	if(K == 1) printf("1\n");
	else {
		fact[0] = 1; for(int i = 1; i <= N; i++) fact[i] = mul(fact[i - 1], i);

		C[K - 2] = 1;
		for(i = K - 2 + 1; i <= N * K; i++) C[i] = mul(mul(C[i - 1], i), fpm(i - (K - 2), MOD - 2));

		F[0][0] = 1;
		for(i = 1; i <= N; i++) {
			F[i][0] = mul(F[i - 1][0], C[i * (K - 1) - 1]);
			for(k = 1; k <= i; k++) F[i][k] = add(F[i][k - 1], mul(F[i - 1][k], C[i * (K - 1) + k - 1]));
		}

		printf("%d", mul(fact[N], F[N][N]));
	}
	return 0;
}