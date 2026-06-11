#include <cstdio>
#include <cmath>

int n, m, d;
char ans[] = {'R', 'G', 'B', 'Y'};
char mat[2510][2510];

int main() {
	scanf("%d%d%d", &n, &m, &d);
	if (d & 1) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j)
				putchar((i + j) % 2 ? 'R' : 'B');
			puts("");
		}
		return 0;
	}
	else if (d == 2) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				int tt = j / 2 % 2, tB = i % 2;
				if (i % 4 < 2) tt = !tt;
				putchar(ans[tt * 2 + tB]);
			}
			puts("");
		}
		return 0;
	}
	d /= 2;
	for (int i = 502; i < 2008; ++i)
		for (int j = 502; j < 2008; ++j)
			if (i % d == 0 && j % d == 0 && (i % (d * 2) == j % (d * 2))) {
				int ind = (i / d) % 2 * 2 + (j / (d * 2)) % 2;
				if (i / (d * 2) % 2) ind ^= 1;
				for (int k = -d; k < d; ++k) {
					int kkk;
					if (k < 0) kkk = d - (-k - 1);
					else kkk = d - k;
					//++kkk;
					for (int l = -kkk; l < kkk; ++l) {
						mat[i + k][j + l] = ans[ind];
					}
				}
			}
	for (int i = 1004; i < 1004 + n; ++i) {
		for (int j = 1004; j < 1004 + m; ++j)
			putchar(mat[i][j]);
		puts("");
	}
	return 0;
}
