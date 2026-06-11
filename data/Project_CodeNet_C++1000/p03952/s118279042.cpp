#include <cstdio>

int N, x;

int main() {
	scanf("%d%d", &N, &x);
	if (x == 1 || x == 2 * N - 1) return puts("No"), 0;
	puts("Yes");
	if (N == 2) return puts("1\n2\n3"), 0;
	if (x == 2) {
		for (int i = 1; i <= 2 * N - 1; ++i)
			printf("%d\n", (N + i) % (2 * N - 1) + 1);
		return 0;
	}
	int c = 0;
	for (int i = 1; i <= N - 3; ++i) {
		for (++c; x - 2 <= c && c <= x + 1; ++c) ;
		printf("%d\n", c);
	}
	printf("%d\n%d\n%d\n%d\n", x - 2, x + 1, x, x - 1);
	for (int i = 1; i <= N - 2; ++i) {
		for (++c; x - 2 <= c && c <= x + 1; ++c) ;
		printf("%d\n", c);
	}
	return 0;
}