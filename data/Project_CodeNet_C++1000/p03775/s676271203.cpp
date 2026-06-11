#include <iostream>
#include <climits>
#include <cmath>
#include <vector>
#include <string>

uint64_t getDigit(uint64_t val)
{
	return std::to_string(val).length();
}

uint64_t F(uint64_t A, uint64_t B)
{
	uint64_t a = getDigit(A);
	uint64_t b = getDigit(B);
	return a > b ? a : b;
}

int main()
{
	uint64_t N;
	uint64_t answer;

	std::cin >> N;

	answer = UINT64_MAX;
	uint64_t limit = std::sqrt(N) + 1;
	for (uint64_t i = 1; i < limit; i++)
	{
		if (N % i == 0)
		{
			uint64_t A = i;
			uint64_t B = N / A;
			uint64_t f = F(A, B);

			if (f < answer)
			{
				answer = f;
			}
		}
	}

	std::cout << answer;

	return 0;
}
