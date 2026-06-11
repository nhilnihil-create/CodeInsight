#include <iostream>

typedef unsigned long long ull;

int CountDigit(ull num)
{
	int ret = 0;
	while (num > 0)
	{
		++ret;
		num /= 10;
	}
	return ret;
}

ull dfs(ull total, ull num, int digit)
{
	ull n = num / digit;
	ull ret = 0;
	if (digit == 10)
	{
		ret += total + n + (num % 10);
		ret += total + num;
	}
	else
	{
		ret += dfs(total + n, num % digit, digit / 10);
		ret += dfs(total, num, digit / 10);
	}
	return ret;
}

int main()
{
	ull S;
	std::cin >> S;

	int size = CountDigit(S);
	ull ans = S;
	if (size > 1)
	{
		int digit = 1;
		while (--size > 0)
		{
			digit *= 10;
		}

		ans = dfs(0, S, digit);
	}

	std::cout << ans << std::endl;
	
	return 0;
}
