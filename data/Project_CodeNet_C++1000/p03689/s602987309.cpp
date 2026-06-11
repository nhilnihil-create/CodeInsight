#include <stdio.h>
int a, b, x, y;
int main() {
	scanf("%d%d%d%d", &a, &b, &x, &y);
	if (!(a % x + b % y)) {
		printf("No\n");
		return 0;
	}
	printf("Yes\n");
	for (int i = 1; i <= a; i++) {
		for (int j = 1; j <= b; j++) {
			if (i % x + j % y) {
				printf("1000");
			}
			else {
				printf("%d", -1000 * x * y + 999);
			}
			if (j == b)printf("\n");
			else printf(" ");
		}
	}
}