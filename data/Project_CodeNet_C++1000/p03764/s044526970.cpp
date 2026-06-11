#include <cstdio>
long long n, m, a, x, y, M=1e9+7;
int main() {
	int i;
	scanf("%lld%lld", &n, &m);
	for(i=0; i<n; i++) {
		scanf("%lld", &a);
		x += a * (i-(n-1-i));
	}
	x %= M;
	for(i=0; i<m; i++) {
		scanf("%lld", &a);
		y += a * (i-(m-1-i));
	}
	y %= M;
	printf("%lld", x*y%M);
	return 0;
}