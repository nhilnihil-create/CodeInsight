#include <bits/stdc++.h>

typedef long long ll;

const int kN = 1e5 + 5;

int a[kN]; ll ans = 0;

int main() {
	int n, lst = 0; scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		int x; scanf("%d", &x);
		if(lst && x) lst = 0, --x, ++ans;
		lst = x % 2; ans += x / 2;
	}
	printf("%lld", ans);
	return 0;
}