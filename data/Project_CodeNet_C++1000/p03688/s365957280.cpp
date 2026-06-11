#include <stdio.h>
int n, x, y, z;
int a[100000];
int main() {
	scanf("%d", &n);
	x = n;
	for (int i = 0; i < n; i++) {
		scanf("%d", a + i);
		if (a[i] < x)x = a[i];
		if (a[i] > y)y = a[i];
	}
	if (y - x > 1) {
		printf("No\n");
		return 0;
	}
	if (y == x) {
		if (y == n - 1)printf("Yes\n");
		else if (y <= n / 2)printf("Yes\n");
		else printf("No\n");
		return 0;
	}
	for (int i = 0; i < n; i++) {
		if (a[i] == x)z++;
	}
	if (z < y && y <= z + (n - z) / 2)printf("Yes\n");
	else printf("No\n");
}