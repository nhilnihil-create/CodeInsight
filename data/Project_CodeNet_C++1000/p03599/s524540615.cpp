#include <stdio.h>
long long a, b, c, d, e, f, m, n;
int x[3001];
int y[3001];
int main() {
	scanf("%lld%lld%lld%lld%lld%lld", &a, &b, &c, &d, &e, &f);
	x[0] = 1;
	y[0] = 1;
	for (int i = 0; i < f; i++) {
		if (x[i]) {
			if (i + 100 * a < f)x[i + 100 * a]++;
			if (i + 100 * b < f)x[i + 100 * b]++;
		}
		if (y[i]) {
			if (i + c < f)y[i + c]++;
			if (i + d < f)y[i + d]++;
		}
	}
	n = 1;
	for (long long i = 1; i <= f; i++) {
		for (long long j = 0; j <= f; j++) {
			if (x[i] && y[j] && i + j <= f && (i / 100 * e) >= j) {
				if (n * j >= m * i + m * j) {
					m = j;
					n = i + j;
				}
			}
		}
	}
	printf("%lld %lld\n", n, m);
}