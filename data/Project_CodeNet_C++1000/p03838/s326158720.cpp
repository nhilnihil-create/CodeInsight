#include <cstdio>
#include <cmath>

int main() {
	int A, B;
	scanf("%d%d", &A, &B);
	if (A + B == 0) puts("1");
	else if (abs(A) < abs(B)) printf("%d\n", abs(B) - abs(A) + (A < 0) + (B < 0));
	else printf("%d\n", abs(A) - abs(B) + (A > 0) + (B > 0));
	return 0;
}