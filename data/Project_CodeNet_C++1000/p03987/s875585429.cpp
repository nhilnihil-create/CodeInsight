#include <stdio.h>
long long n, a, x, ans;
long long l[200002];
long long r[200002];
long long p[200002];
int main() {
	scanf("%lld", &n);
	for (long long i = 1; i <= n; i++) {
		l[i] = i - 1;
		r[i] = i + 1;
	}
	for (long long i = 1; i <= n; i++) {
		scanf("%lld", &a);
		p[a] = i;
	}
	for (int i = n; i; i--) {
		x = p[i];
		ans += i * (r[x] - x) * (x - l[x]);
		l[r[x]] = l[x];
		r[l[x]] = r[x];
	}
	printf("%lld\n", ans);
}