#include <stdio.h>
long long n, x, a, b, c, ans;
int main() {
	scanf("%lld%lld", &n, &x);
	ans = n;
	if (x < n - x) {
		a = n - x;
		b = x;
	}
	else {
		a = x;
		b = n - x;
	}
	while (true) {
		if (a % b == 0) {
			ans += (2 * a / b - 1) * b;
			break;
		}
		else {
			ans += 2 * (a / b) * b;
			c = a % b;
			a = b;
			b = c;
		}
	}
	printf("%lld\n", ans);
}