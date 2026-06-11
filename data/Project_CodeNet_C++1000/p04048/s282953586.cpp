#include <cstdio>

typedef long long LL;

LL N, X;

LL f(LL a, LL b) {
	return b ? a / b * b * 2 + f(b, a % b) : -a;
}

int main() {
	scanf("%lld%lld", &N, &X);
	printf("%lld\n", N + f(X, N - X));
	return 0;
}