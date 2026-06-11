#include <bits/stdc++.h>

const int kN = 1e5 + 5;

int n, a[kN], d[kN];

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", a + i), d[i] = a[i];
	std::sort(d + 1, d + n + 1);
	for(int i = 1; i <= n; ++i) a[i] = std::lower_bound(d + 1, d + n + 1, a[i]) - d;
	int ans1 = 0, ans2 = 0;
	for(int i = 1; i <= n; ++i) {
		ans1 += (a[i] % 2 == 1 && i % 2 == 0);
		ans2 += (a[i] % 2 == 0 && i % 2 == 1);
	}
	printf("%d", std::min(ans1, ans2));
	return 0;
}