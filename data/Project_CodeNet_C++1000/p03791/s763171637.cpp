#include <bits/stdc++.h>
using namespace std;

const int Mod = 1e9 + 7;

int n, x, c, ans = 1;

int main() {
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &x);
		if (x >= ((c << 1) | 1)) {
			c++;
		} else {
			ans = 1ll * ans * (c + 1) % Mod;
		}
	}
	while (ans = 1ll * ans * c % Mod, --c);
	printf("%d\n", ans);
	return 0;
}
