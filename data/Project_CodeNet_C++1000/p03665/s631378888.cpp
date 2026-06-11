#include <cstdio>

int N, P, C;

int main() {
	scanf("%d%d", &N, &P);
	for (int i = 1, x; i <= N; ++i) scanf("%d", &x), C += x & 1;
	if (!C) printf("%lld\n", P ? 0ll : 1ll << N);
	else printf("%lld\n", 1ll << (N - 1));
	return 0;
}