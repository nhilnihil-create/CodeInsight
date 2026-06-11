#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int n, k;
	std::cin >> n >> k;
	std::vector<long long> A;
	std::vector<long long> MAX;
	MAX.push_back(0);
	for (int i = 0; i < n; i++)
	{
		long a;
		std::cin >> a;
		A.push_back(a);
		MAX.push_back(a);
	}
	for (int i = 0; i < n; i++)
	{
		MAX.at(i + 1) = std::max(MAX.at(i), MAX.at(i + 1));
	}
	long long ans = 112345678901;
	for (int bit = 0; bit < (1 << n); bit++)
	{
		std::vector<long long> index;
		for (int i = 0; i < n; i++)
		{
			if (bit & (1 << i))
				index.push_back(i);
		}
		if (index.size() != k)
			continue;
		long long max_height = 0;
		long long cost = 0;
		for (int i = 0; i < k; i++)
		{
			max_height = std::max(max_height, MAX.at(index.at(i)));
			if (A.at(index.at(i)) <= max_height)
			{
				max_height++;
				cost += max_height - A.at(index.at(i));
			}
			else
				max_height = A.at(index.at(i));
		}
		ans = std::min(ans, cost);
	}
	std::cout << ans << '\n';


}
