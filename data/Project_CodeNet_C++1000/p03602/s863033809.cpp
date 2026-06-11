#include <stdio.h>

typedef long long lli;

lli a[301][301], f[301][301];
int n;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%lld", &a[i][j]);
			f[i][j] = a[i][j];
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (f[i][j] > f[i][k] + f[k][j]) f[i][j] = f[i][k] + f[k][j];
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i][j] != f[i][j]) {
				puts("-1");
				return 0;
			}
		}
	}
	lli res = 0;
	for (int u = 1; u <= n; u++) {
		for (int v = u + 1; v <= n; v++) {
			bool found = false;
			for (int k = 1; k <= n; k++) if (k != u && k != v) {
				if (a[u][k] + a[k][v] == a[u][v]) {
					found = true;
					break;
				}
			}
			if (!found) res += a[u][v];
		}
	}
	printf("%lld\n", res);
	return 0;
}