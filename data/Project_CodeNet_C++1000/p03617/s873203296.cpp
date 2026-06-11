#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
#define int long long
#define pb push_back

int q, h, s, d, n, ans;
int32_t main() {
	cin >> q >> h >> s >> d >> n;
	ans = 0;
	h = min(h, q*2);
	s = min(s, h*2);
	d = min(d, s*2);
	while (n > 1) {
		ans += d;
		n -= 2;
	}
	while (n > 0) {
		ans += s;
		n -= 1;
	}
	cout << ans;
}