#include <cstdio>

const int maxn = 1e5 + 100;

int n, m, k, cnt, a[maxn], b[maxn];

int main() {
	scanf("%d%d", &n, &m);
	cnt = 0;
	for (int i = 0; i < m; ++i) {
		scanf("%d", a + i);
		cnt += (a[i] >> 1);
	}
	if(cnt + (n >> 1) < n - 1) {
		return !puts("Impossible");
	}
	if(n & 1) {
		if(m == 1) {
			printf("%d\n", a[0]);
			printf("%d\n", n + 1 >> 1);
			for (int i = 0; i < (n >> 1); ++i) {
				printf("2 ");
			}
			return !puts("1");
		}
		for (int i = 1; i < m; ++i) {
			if(a[i] & 1) {
				a[0] ^= a[i];
				a[i] ^= a[0];
				a[0] ^= a[i];
				break;
			}
		}
		if(a[0] & 1) {
			for (int i = 0; i < (a[0] - 1 >> 1); ++i) {
				b[k++] = 2;
			}
		}
		else {
			for (int i = 0; i < (a[0] >> 2); ++i) {
				b[k++] = 2;
			}
			b[k++] = 1;
			for (int i = 0; i < (a[0] - 2 >> 2); ++i) {
				b[k++] = 2;
			}
		}
		for (int i = 1; i < m; ++i) {
			b[k++] = a[i];
		}
		b[k++] = 1;
	}
	else {
		if(~a[0] & 1) {
			for (int i = 1; i < m; ++i) {
				if(a[i] & 1) {
					a[i] ^= a[0];
					a[0] ^= a[i];
					a[i] ^= a[0];
				}
			}
		}
		for (int i = 1; i < m - 1; ++i) {
			if(a[i] & 1) {
				a[i] ^= a[m - 1];
				a[m - 1] ^= a[i];
				a[i] ^= a[m - 1];
			}
		}
		if(a[0] & 1) {
			for (int i = 0; i < (a[0] - 1 >> 1); ++i) {
				b[k++] = 2;
			}
		}
		else {
			for (int i = 0; i < (a[0] >> 2); ++i) {
				b[k++] = 2;
			}
			b[k++] = 1;
			for (int i = 0; i < (a[0] - 2 >> 2); ++i) {
				b[k++] = 2;
			}
		}
		for (int i = 1; i < m - 1; ++i) {
			b[k++] = a[i];
		}
		if(m > 1) {
			if(a[m - 1] & 1) {
				for (int i = 0; i <= (a[m - 1] >> 1); ++i) {
					b[k++] = 2;
				}
			}
			else {
				b[k++] = a[m - 1];
				b[k++] = 1;
			}
		}
		else {
			b[k++] = 1;
		}
	}
	for (int i = 0; i < m; ++i) {
		printf("%d%c", a[i], " \n"[i == m - 1]);
	}
	printf("%d\n", k);
	for (int i = 0 ; i < k; ++i) {
		printf("%d%c", b[i], " \n"[i == k - 1]);
	}
	return 0;
}