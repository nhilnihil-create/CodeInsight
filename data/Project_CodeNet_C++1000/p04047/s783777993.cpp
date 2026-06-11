#include <cstdio>
#include <algorithm>

const int MN = 205;

int N, A[MN];

int main() {
	scanf("%d", &N), N *= 2;
	for (int i = 1; i <= N; ++i) scanf("%d", &A[i]);
	std::sort(A + 1, A + N + 1);
	int Sum = 0;
	for (int i = 1; i <= N; i += 2) Sum += A[i];
	printf("%d\n", Sum);
	return 0;
}