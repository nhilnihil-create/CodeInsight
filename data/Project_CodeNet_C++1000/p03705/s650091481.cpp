#include <cstdio>

typedef long long LL;

int N, A, B;

int main() {
	scanf("%d%d%d", &N, &A, &B);
	if (A > B) return puts("0"), 0;
	if (N == 1) return printf("%d\n", A == B), 0;
	printf("%lld\n", (LL)B * (N - 2) - (LL)A * (N - 2) + 1);
	return 0;
}