#include <cstdio>
#include <cstring>

const int MN = 105;

int N;
char s[MN], t[MN];

int main() {
	scanf("%d%s%s", &N, s + 1, t + 1);
	for (int i = N + 1; i >= 1; --i)
		if (!strncmp(t + 1, s + N - i + 2, i - 1))
			return printf("%d\n", N + N - i + 1), 0;
	return 0;
}