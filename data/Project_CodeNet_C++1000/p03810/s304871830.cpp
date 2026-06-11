#include <cstdio>
inline int gcd(int x, int y)
{
	while (y)
	{
		int r = x % y;
		x = y;
		y = r;
	}
	return x;
}
const char ans[][15] = {"First", "Second"};
int arr[100005];
int main()
{
	// freopen("AGC010-D.in", "r", stdin);
	int n, rev = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);
	while (true)
	{
		int cnt = 0;
		for (int i = 0; i < n; i++)
			cnt += arr[i] & 1 ^ 1;
		if (cnt & 1)
		{
			puts(ans[rev]);
			return 0;
		}
		if (n - cnt >= 2)
		{
			puts(ans[!rev]);
			return 0;
		}
		int g = 0;
		for (int i = 0; i < n; i++)
		{
			if (arr[i] == 1)
			{
				puts(ans[!rev]);
				return 0;
			}
			if (arr[i] & 1)
				arr[i]--;
			g = gcd(g, arr[i]);
		}
		for (int i = 0; i < n; i++)
			arr[i] /= g;
		rev ^= 1;
	}
	return 0;
}
