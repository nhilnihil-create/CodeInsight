#include <cstdio>
#include <algorithm>

const int MN = 100005;

int N, M, A[MN];

int main() {
	scanf("%d%d", &N, &M);
	int C = 0;
	for (int i = 1; i <= M; ++i) scanf("%d", &A[i]), C += A[i] & 1;
	if (C > 2) return puts("Impossible"), 0;
	int p1 = 0, p2 = 0;
	for (int i = 1; i <= M; ++i)
		if (A[i] & 1) (p1 ? p2 : p1) = i;
	if (p1 && !p2) std::swap(A[1], A[p1]);
	if (p2) std::swap(A[1], A[p1]), std::swap(A[p2], A[M]);
	for (int i = 1; i <= M; ++i) printf("%d%c", A[i], " \n"[i == M]);
	if (N == 1) return puts("1\n1"), 0;
	if (M == 1) return printf("2\n1 %d\n", N - 1), 0;
	--A[1], ++A[M];
	printf("%d\n", M - !A[1]);
	for (int i = A[1] ? 1 : 2; i <= M; ++i) printf("%d%c", A[i], " \n"[i == M]);
	return 0;
}