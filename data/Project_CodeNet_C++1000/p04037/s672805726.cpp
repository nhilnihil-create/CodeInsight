#include <stdio.h>
#include <algorithm>
int n, m, x, y;
int a[100000];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", a + i);
	}
	std::sort(a, a + n);
	while (a[n - 1 - m] > m)m++;
	x = a[n - m] - m + 1;
	for (int i = 0; i <= n - m; i++) {
		if (a[i] >= m)y++;
	}
	if (x % 2 && y % 2) printf("Second\n");
	else printf("First\n");
}