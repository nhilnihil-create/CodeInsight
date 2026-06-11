#include <cstdio>
int arr[505], sz_l[505], sz_r[505], ans[300005];
int main()
{
	// freopen("AGC008-D.in", "r", stdin);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", arr + i);
		arr[i]--;
	}
	for (int i = 0; i < n * n; i++)
	{
		ans[i] = -1;
		for (int j = 0; j < n && -1 == ans[i]; j++)
		{
			if (arr[j] == i)
				ans[i] = j;
		}
		int pos = -1;
		for (int j = 0; j < n && -1 == ans[i]; j++)
		{
			if (i < arr[j] && sz_l[j] < j && (pos == -1 || arr[j] < arr[pos]))
				pos = j;
		}
		if (~pos)
		{
			ans[i] = pos;
			sz_l[pos]++;
		}
		for (int j = 0; j < n && -1 == ans[i]; j++)
		{
			if (arr[j] < i && sz_r[j] < n - j - 1)
			{
				ans[i] = j;
				sz_r[j]++;
			}
		}
		if (ans[i] == -1)
		{
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	for (int i = 0; i < n * n; i++)
		printf("%d%c", ans[i] + 1, " \n"[i + 1 == n * n]);
	return 0;
}
