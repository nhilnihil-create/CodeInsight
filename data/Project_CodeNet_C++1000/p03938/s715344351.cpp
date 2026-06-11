#include <cstdio>

const int V = 500000000;
const int MN = 20005;

int N, A[MN];

int main() {
	scanf("%d", &N);
	for (int i = 1, x; i <= N; ++i) scanf("%d", &x), A[x] = i;
	for (int i = 1; i <= N; ++i) printf("%d%c", N * i, " \n"[i == N]);
	for (int i = 1; i <= N; ++i) printf("%d%c", V + A[i] - N * i, " \n"[i == N]);
	return 0;
}