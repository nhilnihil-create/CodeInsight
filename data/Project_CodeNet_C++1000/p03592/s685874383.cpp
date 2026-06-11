#include <cstdio>

int main() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	bool flag = 0;
	for (int i = 0; i <= n; ++i)
		for (int j = 0; j <= m; ++j)
			if (i * m + j * n - i * j * 2 == k) {
				flag = 1;
				break;
			}
	puts(flag ? "Yes" : "No");
	return 0;
}
