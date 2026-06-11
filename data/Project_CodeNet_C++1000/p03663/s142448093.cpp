#include <bits/stdc++.h>

typedef long long LL;

bool query(LL n) {char ch; std::cout << "? " << n << std::endl, std::cin >> ch; return ch == 'Y';}

int main() {
	std::ios::sync_with_stdio(0), std::cin.tie(0);
	if (query(1e10)) {
		int l = 0, r = 8, ans = 9;
		while (l <= r) {
			int mid = l + r >> 1;
			if (query(pow(10, mid + 1) - 1))
				ans = mid, r = mid - 1;
			else l = mid + 1;
		}
		std::cout << "! " << (LL) pow(10, ans) << '\n';
	} else {
		int l = 1, r = 8, ans = 0;
		while (l <= r) {
			int mid = l + r >> 1;
			if (query(pow(10, mid)))
				ans = mid, l = mid + 1;
			else r = mid - 1;
		}
		l = pow(10, ans), r = l * 10 - 2, ans = r + 1;
		while (l <= r) {
			int mid = l + r >> 1;
			if (query(mid * 10LL))
				ans = mid, r = mid - 1;
			else l = mid + 1;
		}
		std::cout << "! " << ans << '\n';
	}
	return 0;
}