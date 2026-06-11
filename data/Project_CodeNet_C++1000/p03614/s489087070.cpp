#include <bits/stdc++.h>

using namespace std;

int n;
int a[200001];
int ans = 0;
int main( ) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i ++) {
		if (a[i] != i) continue;
		int tmp = i;
		while (tmp <= n && a[tmp] == tmp) ++ tmp;
		-- tmp;
		int sz = tmp - i + 1;
		ans += (sz + 1) / 2;
		i = tmp;
	}
	printf("%d\n", ans);
	return 0;
}
