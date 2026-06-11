#include <cstdio>

const int MN = 100005;

int N, L, A[MN];

int main() {
	scanf("%d%d", &N, &L);
	for (int i = 1; i <= N; ++i) scanf("%d", &A[i]);
	int ok = 0;
	for (int i = 1; i < N; ++i) if (A[i] + A[i + 1] >= L) ok = i;
	if (!ok) return puts("Impossible"), 0;
	puts("Possible");
	for (int i = 1; i < ok; ++i) printf("%d\n", i);
	for (int i = N - 1; i >= ok; --i) printf("%d\n", i);
	return 0;
}