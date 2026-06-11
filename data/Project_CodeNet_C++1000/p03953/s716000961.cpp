#include <stdio.h>
int n, m, a, b, c, d;
long long x[100000];
long long k;
int s[100000];
int t[100000];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", x + i);
		s[i] = i;
	}
	for (int i = n - 1; i; i--)x[i] -= x[i - 1];
	scanf("%d%lld", &m, &k);
	for (int i = 0; i < m; i++) {
		scanf("%d", &a);
		b = s[a - 1];
		s[a - 1] = s[a];
		s[a] = b;
	}
	for (int i = 1; i < n; i++) {
		if (t[i])continue;
		c = s[i];
		d = 1;
		while (c != i) {
			c = s[c];
			d++;
		}
		b = k % d;
		c = i;
		for (int j = 0; j < b; j++) {
			c = s[c];
		}
		b = i;
		for (int j = 0; j < d; j++) {
			t[b] = c;
			b = s[b];
			c = s[c];
		}
	}
	k = 0;
	for (int i = 0; i < n; i++) {
		k += x[t[i]];
		printf("%lld\n", k);
	}
}