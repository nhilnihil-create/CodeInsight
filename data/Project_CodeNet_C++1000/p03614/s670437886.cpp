#include <cstdio>

int N, nums[100000], t, cnt = 0;

int main(void)
{
	//freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	for (int n = 0; n < N; ++n)
		scanf("%d", nums + n);
	for (int n = 0; n < N - 1; ++n)
	{
		if (nums[n] == n + 1)
		{
			t = nums[n];
			nums[n] = nums[n + 1];
			nums[n + 1] = t;
			++cnt;
		}
	}
	if (nums[N - 1] == N)
	{
		t = nums[N - 1];
		nums[N - 1] = nums[N - 2];
		nums[N - 2] = t;
		++cnt;
	}
	printf("%d", cnt);
	return 0;
}