#include <iostream>
#include <climits>
#include <cmath>
#include <vector>

int main()
{
	int N;
	int M;
	std::vector<int> a;
	std::vector<int> b;
	std::vector<int> c;
	std::vector<int> d;
	std::vector<int> answer;

	std::cin >> N >> M;

	a.resize(N);
	b.resize(N);
	for (int i = 0; i < N; i++)
	{
		std::cin >> a[i] >> b[i];
	}

	c.resize(M);
	d.resize(M);
	for (int i = 0; i < M; i++)
	{
		std::cin >> c[i] >> d[i];
	}

	answer.resize(N);
	for (int i = 0; i < N; i++)
	{
		int min_distance = INT_MAX;
		answer[i] = 0;

		for (int j = 0; j < M; j++)
		{
			int distance = std::abs(a[i] - c[j]) + std::abs(b[i] - d[j]);
			if (min_distance > distance)
			{
				min_distance = distance;
				answer[i] = j + 1;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		std::cout << answer[i] << std::endl;
	}

	return 0;
}
