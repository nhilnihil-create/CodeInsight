#include <bits/stdc++.h>

using ll = long long;
using ld = long double;
constexpr ll inf = static_cast<ll>(1e17);
constexpr ll mod = static_cast<ll>(1e9 + 7);

int n;
ll a[305][305];
ll d[305][305];
int main() {
	std::cin >> n;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			std::cin >> a[i][j];
			d[i][j] = inf;
		}

	for (int k = 0; k < n; ++k)
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				d[i][j] = std::min(a[i][j], d[i][k] + d[k][j]);

	ll ans = 0;
	bool ok = true;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			if (d[i][j] < a[i][j])
				ok = false;
			else {
				bool f = true;
				for (int k = 0; k < n; ++k) {
					if (k == i || k == j)
						continue;

					if (d[i][k] + d[k][j] == a[i][j])
						f = false;
				}

				if (f)
					ans += a[i][j];
			}
		}

	if (ok)
		std::cout << ans / 2 << std::endl;
	else
		std::cout << -1 << std::endl;

	return 0;
}
