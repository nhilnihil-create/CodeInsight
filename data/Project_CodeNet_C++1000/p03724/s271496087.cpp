#include <cstdio>

const int MN = 100005;

int N, Q, b[MN], x;

int main() {
	scanf("%d%d", &N, &Q), Q *= 2;
	while (Q--) scanf("%d", &x), b[x] ^= 1;
	for (int i = 1; i <= N; ++i) if (b[i]) return puts("NO"), 0;
	puts("YES");
	return 0;
}