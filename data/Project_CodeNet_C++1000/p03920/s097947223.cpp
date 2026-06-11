#include <bits/stdc++.h>

int main()
{
	int N;
	scanf("%d", &N);
	int sum{}, count{1};
	while (sum <= N)
	{
		sum += count;
		count++;
	}
	count--;
	std::vector<int> ans;
	for (int i{1}; i <= count; i++)
		if (i != sum - N)
			printf("%d\n", i);

	return 0;
}