#include <cstdio>

typedef long long LL;

int main() {
	int Q, H, S, D; LL N;
	scanf("%d%d%d%d%lld", &Q, &H, &S, &D, &N);
	if (H > 2 * Q) H = 2 * Q;
	if (S > 2 * H) S = 2 * H;
	if (D > 2 * S) D = 2 * S;
	printf("%lld\n", N / 2 * D + N % 2 * S);
	return 0;
}