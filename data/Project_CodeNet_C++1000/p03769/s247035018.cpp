#include <cstdio>
int arr[205], ans[205];
int main()
{
	// freopen("AGC012-C.in", "r", stdin);
	long long n;
	scanf("%lld", &n);
	n++;
	int cnt = 0, len = 0;
	while (n != 1)
	{
		cnt += n & 1;
		arr[len++] = n & 1;
		n >>= 1;
	}
	int l = cnt - 1, r = cnt, cur = 0;
	for (int i = len - 1; i >= 0; i--)
	{
		ans[r++] = cur++;
		if (arr[i])
			ans[l--] = cur++;
	}
	printf("%d\n", r << 1);
	for (int i = 0; i < r << 1; i++)
		printf("%d%c", i < r ? ans[i] + 1 : i - r + 1, " \n"[i + 1 == r << 1]);
	return 0;
}
