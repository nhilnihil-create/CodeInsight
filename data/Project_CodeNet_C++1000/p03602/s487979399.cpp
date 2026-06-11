#include <stdio.h>

int a[512][512];
int b[512][512];
int n;

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
			b[i][j] = a[i][j];
		}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (b[i][j] > b[i][k] + b[k][j]) {
					printf("-1\n"); return 0;
				}
			}
		}
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (b[i][j] == b[i][k] + b[k][j] && b[i][k] > 0 && b[k][j] > 0) {
					b[i][j] = -1;
				}
			}
		}
	}

	long long total = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (b[i][j] > 0) {
				total += b[i][j];
			}
		}
	}
	printf("%lld\n", total / 2);
	return 0;
}