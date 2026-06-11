#include <cstdio>

int N, x, s;

int main() {
	scanf("%d", &N);
	while (N--) scanf("%d", &x), s ^= x;
	puts(s & 1 ? "NO" : "YES");
	return 0;
}