#include <bits/stdc++.h>

typedef long long LL;
bool qry(LL v) {
	std::cout << "? " << v << std::endl;
	static char buf[10]; std::cin >> buf;
	return *buf == 'Y';
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	LL nx = 9999999999;
	int dd = 0;
	int l = 10, r = 0, c = 0;
	for (int i = 9; ~i; --i) {
		if (qry(nx) && qry((nx + 1) / 10)) {
			dd = i; l = std::min(l, i), r = std::max(r, i), ++c;
		}
		nx /= 10;
	}
	if (r - l + 1 == c && r == 9) dd = l; else dd = r;
	LL now = 0;
	for (int j = dd; j; --j) {
		int l = 0, r = 9; LL ans = 0;
		while (l <= r) {
			int mid = l + r >> 1;
			LL t = now * 10 + mid;
			if (!qry(t)) r = mid - 1;
			else ans = t, l = mid + 1;
		}
		now = ans;
	}
	now *= 100; now += 9; LL ans = 0;
	for (int j = dd == 0; j < 10; ++j)
		if (qry(now + j * 10)) {
			ans = now / 10 + j; break;
		}
	std::cout << "! " << ans << std::endl;
	return 0;
}
