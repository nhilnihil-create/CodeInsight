#include <cstdio>
#include <algorithm>

const int MN = 100005;

int N, A[MN];

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) scanf("%d", &A[i]);
	std::sort(A + 1, A + N + 1);
	int o = 0;
	for (int i = 1, S = 0; i < N && S < 5e8; ++i)
		S += A[i], o = 2 * S < A[i + 1] ? i : o;
	printf("%d\n", N - o);
	return 0;
}