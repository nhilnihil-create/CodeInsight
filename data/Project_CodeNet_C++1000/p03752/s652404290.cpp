#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using uint = unsigned int;

constexpr int64_t INF = static_cast<int64_t>(1) << 60;

int main()
{
	uint N, K;
	cin >> N >> K;
	vector<int64_t> a(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> a[i];
	}

	int64_t min_yen = INF;
	for (int i = 0; i < 1 << N; ++i)
	{
		if (__builtin_popcount(i) != K)
		{
			continue;
		}

		int64_t max_height = a[0];
		int64_t yen = 0;
		for (int j = 1; j < N; ++j)
		{
			if ((i & (1 << j)) != 0)
			{
				if (a[j] <= max_height)
				{
					yen += max_height - a[j] + 1;
					++max_height;
				}
				else
				{
					max_height = a[j];
				}
			}
			else
			{
				if (a[j] > max_height)
				{
					yen = INF;
					break;
				}
			}
		}

		min_yen = min(yen, min_yen);
	}

	cout << min_yen << endl;

	return 0;
}