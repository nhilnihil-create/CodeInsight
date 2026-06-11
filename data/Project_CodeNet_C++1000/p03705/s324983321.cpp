#include <bits/stdc++.h>

int n, a, b;

int main()
{
	std::cin >> n >> a >> b; if (a > b) return puts("0"), 0;
	if (n == 1) return std::cout << (a == b) << std::endl, 0;
	return std::cout << 1ll * (n - 2) * (b - a) + 1 << std::endl, 0;
}