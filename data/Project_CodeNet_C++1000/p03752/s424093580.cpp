#include <stdio.h>
long long n, k, t, s, m, f;
long long a[15];
int b[15];
long long c[15];
int main() {
	scanf("%lld%lld", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%lld", a + i);
	}
	m = 20000000000;
	for (int i = 0; i < (1 << n); i++) {
		t = i;
		s = 0;
		c[0] = 0;
		f = 0;
		for (int j = 0; j < n; j++) {
			b[j] = t % 2;
			t /= 2;
			if (b[j])s++;
		}
		if (s < k)continue;
		t = 0;
		f = 0;
		for (int j = 0; j < n; j++) {
			if (b[j]) {
				if (f >= a[j]) {
					f++;
					t += f - a[j];
				}
			}
			if (f < a[j])f = a[j];
		}
		if (t < m)m = t;
	}
	printf("%lld\n", m);
}