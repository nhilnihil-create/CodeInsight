#include <iostream>
#include <algorithm>
#include <cmath>

int n;
long long a[100005], t;
int main()
{
	std::cin >> n >> t;
	for (int i = 0; i < n; ++i)
		std::cin >> a[i];

	long long max = 0;
	long long dis = 0;
	int dc = 1, mc = 1;
	for (int i = n - 1; i >= 0; --i) {
		auto d = max - a[i];

		if (d > dis) {
			dis = d;
			dc = 1;
		}
		else if (d == dis)
			++dc;

		if (a[i] > max) {
			max = a[i];
			mc = 1;
		}
		else if (a[i] == max)
			++mc;
	}

	std::cout << dc * mc << std::endl;
	return 0;
}
