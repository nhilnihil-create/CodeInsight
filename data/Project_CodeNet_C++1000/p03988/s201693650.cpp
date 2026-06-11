#include <cstdio>
#include <algorithm>

const int MN = 105;

int N, A[MN], B[MN];

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) scanf("%d", &A[i]), ++B[A[i]];
	std::sort(A + 1, A + N + 1);
	int len = A[N];
	for (int i = 0; i <= len; ++i) --B[std::max(len - i, i)];
	for (int i = 1; i <= N; ++i) if (B[i] < 0) return puts("Impossible"), 0;
	int hlen = (len + 1) / 2;
	for (int i = 1; i <= hlen; ++i) if (B[i]) return puts("Impossible"), 0;
	puts("Possible");
	return 0;
}