#include <stdio.h>
int n, m, r;
int a, b, c, e, f, z;
int k[9];
int p[8];
int q[8];
int x[8];
int y[8];
int d[200][200];
int main() {
	scanf("%d%d%d", &n, &m, &r);
	for (int i = 0; i < r; i++) {
		scanf("%d", p + i);
		p[i]--;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			d[i][j] = 100000000;
		}
	}
	for (int i = 0; i < n; i++)d[i][i] = 0;
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &a, &b, &c);
		a--;
		b--;
		if (d[a][b] > c) {
			d[a][b] = c;
			d[b][a] = c;
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					if (d[j][k] > d[j][a] + c + d[b][k]) {
						d[j][k] = d[j][a] + c + d[b][k];
					}
					if (d[j][k] > d[j][b] + c + d[a][k]) {
						d[j][k] = d[j][b] + c + d[a][k];
					}
				}
			}
		}
	}
	k[0] = 1;
	for (int i = 1; i <= r; i++) {
		k[i] = k[i - 1] * i;
	}
	z = 100000000;
	for (int i = 0; i < k[r]; i++) {
		f = i;
		for (int j = 0; j < r; j++) {
			q[j] = f / k[r - 1 - j];
			f %= k[r - 1 - j];
			y[j] = 0;
		}
		for (int j = 0; j < r; j++) {
			e = q[j];
			f = 0;
			while (e || y[f]) {
				if (!y[f])e--;
				f++;
			}
			x[j] = f;
			y[f]++;
		}
		f = 0;
		for (int j = 0; j < r - 1; j++) {
			f += d[p[x[j]]][p[x[j + 1]]];
		}
		if (z > f)z = f;
	}
	printf("%d\n", z);
}