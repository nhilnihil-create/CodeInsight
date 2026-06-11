#include <bits/stdc++.h>

int n, p[100005];
int main()
{
	std::cin >> n;
	for (int i = 0; i < n; ++i)
		std::cin >> p[i];

	long long ans = 0;
	bool before = false;
	for (int i = 0; i < n; ++i) {
		if (p[i] == i + 1) {
			if (!before)
				++ans;
			before = !before;
		}
		else
			before = false;
	}

	std::cout << ans << std::endl;
	return 0;
}
