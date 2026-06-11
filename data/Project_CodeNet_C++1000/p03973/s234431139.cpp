#include <bits/stdc++.h>
using namespace std;

const int maxn = 100005;

int n, lst;
int a[maxn];
long long ans;

signed main () {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) 
		scanf("%d", &a[i]);
	ans = a[1] - 1, a[1] = 1;
	lst = 1;
	for (int i = 2; i <= n; ++i) {
		if (lst != a[i] - 1) {
			ans += (a[i] - 1) / (lst + 1);
			a[i] = 1;
		}
		lst = max(lst, a[i]);
	}
	printf("%lld\n", ans);
}
