#include <cstdio>

typedef long long LL;

int N, A, B;
LL C, D;

int main() {
	scanf("%d%d%d%lld%lld", &N, &A, &B, &C, &D), --N;
	for (int k = 0; k <= N; ++k)
		if (A + k * C - (N - k) * D <= B && B <= A + k * D - (N - k) * C) return puts("YES"), 0;
	puts("NO");
	return 0;
}