#include <bits/stdc++.h>
using namespace std;

const long long inf = 1000000000000000037;
const int maxn = 100005;

int n, mx;
int a[3 * maxn];
multiset < int > b, c, others;
long long sb, sc, ans;

signed main () {
	scanf("%d", &n);
	for (int i = 1; i <= 3 * n; ++i) {
		scanf("%d", &a[i]);
		if (i <= n) {
			b.insert(a[i]);
			sb += a[i];
		}
		else {
			if (int(c.size()) == n && *prev(c.end()) > a[i]) {
				sc -= *prev(c.end());
				others.insert(*prev(c.end()));
				c.erase(prev(c.end()));
				sc += a[i];
				c.insert(a[i]);
			}
			else if (int(c.size()) == n)
				others.insert(a[i]);
			else {
				c.insert(a[i]);
				sc += a[i];
			}
		}
	}
	ans = sb - sc;
	for (int i = n + 1; i <= 2 * n; ++i) {
		if (a[i] > *b.begin()) {
			sb -= *b.begin();
			b.erase(b.begin());
			sb += a[i];
			b.insert(a[i]);
		}
		if (others.find(a[i]) != others.end()) 
			others.erase(others.find(a[i]));
		else {
			sc -= a[i];
			c.erase(c.find(a[i]));
			sc += *others.begin();
			c.insert(*others.begin());
			others.erase(others.begin());
		}
		ans = max(ans, sb - sc);
	}
	printf("%lld\n", ans);
}
