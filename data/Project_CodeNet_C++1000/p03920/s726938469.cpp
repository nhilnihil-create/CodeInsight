#include <bits/stdc++.h>

int main()
{
	int N;
	scanf("%d", &N);
	int sum{};
	for (int i{1}; i <= N; i++)
	{
		sum += i;
		if (sum >= N)
		{
			for (int j{1}; j <= i; j++)
				if (j != sum - N)
					printf("%d\n", j);
			return 0;
		}
	}

	return 0;
}