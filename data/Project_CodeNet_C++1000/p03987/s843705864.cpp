#include <bits/stdc++.h>
using namespace std;

const int maxn = 200005;

int n, l, r;
int a[maxn], pos[maxn];
long long ans;
set < int > border;
set < int > :: iterator j;

signed main () {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		pos[a[i]] = i;
	}
	for (int i = 1; i <= n; ++i) {
		l = 0, r = n + 1;
		j = border.upper_bound(pos[i]);
		if (j != border.end())
			r = *j;
		if (j != border.begin())
			l = *prev(j);
		ans += ((long long) i) * ((long long) pos[i] - l) * ((long long) r - pos[i]);
		border.insert(pos[i]);
	}
	printf("%lld\n", ans);
}
