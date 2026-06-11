#include <cstdio>
 
int A, B;
 
int main() {
	scanf("%d%d", &A, &B);
	if (A <= 0 && B >= 0) puts("Zero");
	else if (A > 0 || (B - A) & 1) puts("Positive");
	else puts("Negative");
	return 0;
}