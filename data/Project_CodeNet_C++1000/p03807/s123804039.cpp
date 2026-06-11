#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;
int n, ans, a[N];
signed main () {
	scanf ("%lld", &n);
	for (int i = 1; i <= n; i ++) {
		scanf ("%lld", &a[i]);
		if (a[i] & 1)
			ans ^= 1;
	}
	if (ans)
		puts ("NO");
	else
		puts ("YES");
	return 0;
}
