#include <bits/stdc++.h>
using namespace std;

const int maxn = 100005;

int n, mx = -1, mn = maxn;
int a[maxn], cnt[maxn];

signed main () {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		++cnt[a[i]];
		mn = min(mn, a[i]), mx = max(mx, a[i]);
	}
	if (mx - mn > 1)
		printf("No\n");
	else if (mx == mn) {
		if (mx == n - 1 || 2 * mx <= n)
			printf("Yes\n");
		else
			printf("No\n");
	}
	else {
		if (cnt[mn] + 1 <= mx && mx <= cnt[mn] + cnt[mx] / 2)
			printf("Yes\n");
		else
			printf("No\n");
	}
}
