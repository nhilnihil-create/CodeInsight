#include <cstdio>

int main() {
	long long A, B, C;
	scanf("%lld%lld%lld", &A, &B, &C);
	if (~A & 1 || ~B & 1 || ~C & 1) puts("0");
	else printf("%lld\n", A > B ? A > C ? B * C : A * B : B > C ? A * C : A * B);
	return 0;
}