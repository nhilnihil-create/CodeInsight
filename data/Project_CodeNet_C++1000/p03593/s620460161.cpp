#include <cstdio>

char str[110][110];
int ct[130];

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		scanf("%s", str + i);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			++ct[str[i][j]];
	bool flag = 1;
	if (n % 2 == 0 && m % 2 == 0) {
		for (int i = 0; i < 130; ++i)
			if (ct[i] % 4)
				flag = 0;
	}
	else if (n % 2 == 0 || m % 2 == 0) {
		int cA = 0;
		for (int i = 0; i < 130; ++i)
			if (ct[i] % 4) {
				if (ct[i] % 4 != 2)
					flag = 0;
				++cA;
			}
		if (m % 2 == 0 && cA > m / 2 || n % 2 == 0 && cA > n / 2) flag = 0;
	}
	else {
		int cA = 0, cB = 0;
		for (int i = 0; i < 130; ++i)
			if (ct[i] % 4) {
				if (ct[i] % 4 == 3) ++cA, ++cB;
				if (ct[i] % 4 == 1) ++cA;
				else ++cB;
			}
		if (cA != 1 || cB > m / 2 + n / 2) flag = 0;
	}
	puts(flag ? "Yes" : "No");
	return 0;
}
