#include <cstdio>
long long x[100000], s[100000];
long long const p = 1000000007;
long long prodsum(int n) {
	int i;
	for (i = 0; i < n; i++)scanf("%lld", &x[i]);
	for (i = n - 1; i > 0; i--)x[i] -= x[i - 1];
	s[0] = 0;
	for (i = 1; i <= n / 2; i++)s[i] = s[i - 1] + n - 1 - 2 * (i - 1);
	for (i = n - 1; i >= n / 2; i--)s[i] = s[n - i];
	long long sum = 0;
	for (i = 1; i < n; i++)sum += x[i] * s[i] % p;
	return sum%p;
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	printf("%lld", prodsum(n)*prodsum(m) % p);
	return 0;
}