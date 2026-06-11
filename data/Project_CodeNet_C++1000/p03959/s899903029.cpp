#include <stdio.h>
int n;
long long t[100000];
long long a[100000];
int ft[100000];
int fa[100000];
long long x;
long long p = 1000000007;
int main() {
	x = 1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", t + i);
	}
	for (int i = 0; i < n; i++) {
		scanf("%lld", a + i);
	}
	ft[0] = t[0];
	fa[n - 1] = a[n - 1];
	for (int i = 1; i < n; i++) {
		if (t[i] > t[i - 1])ft[i] = 1;
		if (a[i - 1] > a[i])fa[i - 1] = 1;
	}
	for (int i = 0; i < n; i++) {
		if (ft[i] && fa[i]) {
			if (t[i] != a[i])x = 0;
		}
		else if (!ft[i] && !fa[i]) {
			if (t[i] < a[i])x *= t[i];
			else x *= a[i];
			x %= p;
		}
		else {
			if (ft[i]) {
				if (t[i] > a[i])x = 0;
			}
			else if (a[i] > t[i])x = 0;
		}
	}
	printf("%lld\n", x);
}