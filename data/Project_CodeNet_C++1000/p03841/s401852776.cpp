#include <algorithm>
#include <cstdio>
int arr[505], ans[300005], sz[505];
int main()
{
	// freopen("AGC008-D.in", "r", stdin);
	int n;
	scanf("%d", &n);
	std::for_each(arr, arr + n, [&] (int &x) { scanf("%d", &x); });
	for (int i = 1; i <= n * n; i++)
	{
		ans[i] = -1;
		for (int j = 0; j < n && -1 == ans[i]; j++)
		{
			if (arr[j] == i)
				ans[i] = j;
		}
		int mnp = -1;
		for (int j = 0; j < n && -1 == ans[i]; j++)
		{
			if (i < arr[j] && sz[j] < j && (mnp == -1 || arr[j] < arr[mnp]))
				mnp = j;
		}
		if (~mnp)
		{
			sz[mnp]++;
			ans[i] = mnp;
		}
		for (int j = 0; j < n && -1 == ans[i]; j++)
		{
			if (arr[j] < i && sz[j] < n - 1)
			{
				if (sz[j] < j)
				{
					puts("No");
					return 0;
				}
				ans[i] = j;
				sz[j]++;
			}
		}
		if (-1 == ans[i])
		{
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	for (int i = 1; i <= n * n; i++)
		printf("%d%c", ans[i] + 1, " \n"[i == n * n]);
	return 0;
}
