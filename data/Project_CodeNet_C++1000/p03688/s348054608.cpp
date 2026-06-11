#include <bits/stdc++.h>

using namespace std;

int c[100010];

int main() {
	ios::sync_with_stdio(false);
	int n, x;
	cin >> n;
	int mi = n + 2, mx = -1;
	for(int i = 1; i <= n; i++) {
		cin >> x;
		c[x]++;
		mi = min(mi, x);
		mx = max(mx, x);
	}
	if(mx - mi > 1) puts("No");
	else if(mx == mi) {
		if(mi == n - 1 || (mi << 1) <= n) puts("Yes");
		else puts("No");
	} else {
		int c1 = c[mi], c2 = c[mx];
		if(c1 > mi) puts("No");
		else if(n - c1 >= (mx - c1) * 2) puts("Yes");
		else puts("No");
	}
	return 0;
}