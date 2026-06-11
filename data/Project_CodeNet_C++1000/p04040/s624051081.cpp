#include<cstdio>
#define R 100001
#define MOD 1000000007
int h, w, a, b;
long long way[R];
long long mul(long long x, long long y, long long p) {
	long long res = 1;
	while (y > 0) {
		if (y % 2 != 0) {
			res *= x;
			res %= p;
		}
		x *= x;
		x %= p;
		y /= 2;
	}
	return res;
}
int main() {
	scanf("%d%d%d%d", &h, &w, &a, &b);
	int i;
	long long comba=1,combb=1;
	long long ans = 0;
	for (i = 0; i < h - a; i++) {
		if (i > 0) {
			comba *= (b + i-1);
			comba %= MOD;
			combb *= i;
			combb %= MOD;
		}
		long long combc = mul(combb, MOD - 2, MOD);
		way[i] = (comba*combc) % MOD;
	}
	comba = 1; combb = 1;
	for (i = 1; i < a; i++) {
		comba *= (w - b - 1+i);
		combb *= i;
		comba %= MOD;
		combb %= MOD;
	}
	for (i = a; i < h; i++) {
		comba *= (w - b - 1 + i);
		combb *= i;
		comba %= MOD;
		combb %= MOD;
		long long combc = mul(combb, MOD - 2, MOD);
		long long comb = (comba*combc) % MOD;
		long long next = (comb * way[h-1 - i])%MOD;
		ans = (ans + next) % MOD;
	}
	printf("%lld", ans);
	return 0;
}