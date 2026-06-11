#include <bits/stdc++.h>

int n;
long long a, b, h[100005];
int main()
{
	std::cin >> n >> a >> b;
	for (int i = 0; i < n; ++i)
		std::cin >> h[i];

	std::sort(h, h + n, std::greater<long long>());

	long long lb = -1, ub = 1000000005;
	while (ub - lb > 1) {
		auto mid = (lb + ub) / 2;

		long long cnt = 0;
		for (int i = 0; i < n; ++i)
			cnt += std::max(0LL, (h[i] - mid * b + a - b - 1) / (a - b));

		if (mid >= cnt)
			ub = mid;
		else
			lb = mid;
	}

	std::cout << ub << std::endl;
	return 0;
}
