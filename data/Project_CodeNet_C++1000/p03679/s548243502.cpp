#include <stdio.h>
int x, a, b;
int main() {
	scanf("%d%d%d", &x, &a, &b);
	if (b <= a)printf("delicious\n");
	else if (b <= a + x)printf("safe\n");
	else printf("dangerous\n");
}