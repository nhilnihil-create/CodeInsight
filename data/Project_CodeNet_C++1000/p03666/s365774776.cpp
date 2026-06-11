#include <bits/stdc++.h>

using ll = long long;
constexpr ll inf = static_cast<ll>(1e17);
constexpr ll mod = static_cast<ll>(1e9 + 7);

int n;
ll a, b, c, d;
int main()
{
	std::cin >> n >> a >> b >> c >> d;


	bool ok = false;
	for (int i = 0; i < n; ++i)
		if (c*(n - 1 - i) - d * i <= b - a && b - a <= -c * i + (n - 1 - i)*d)
			ok = true;

	if (ok)
		std::cout << "YES" << std::endl;
	else
		std::cout << "NO" << std::endl;
	return 0;
}
