#include <stdio.h>
int n;
long long x;
long long a[100000];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", a + i);
	}
	for (int i = 0; i < n - 1; i++) {
		x += a[i] / 2;
		a[i] = a[i] % 2;
		if (a[i] && a[i + 1]) {
			x++;
			a[i + 1]--;
		}
	}
	x += a[n - 1] / 2;
	printf("%lld\n", x);
}