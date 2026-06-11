#include <cstdio>
#include <algorithm>
#include <vector>
#define file(x) freopen(#x".in", "r", stdin), freopen(#x".out", "w", stdout)

inline int read()
{
	int data = 0, w = 1; char ch = getchar();
	while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
	if (ch == '-') w = -1, ch = getchar();
	while (ch >= '0' && ch <= '9') data = data * 10 + (ch ^ 48), ch = getchar();
	return data * w;
}

const int N(2e5 + 10);
int n, a[N];

int check(int mid)
{
	for (int i = 0; i < n - 1; i++)
	{
		if ((a[n - i] >= mid && a[n - i - 1] >= mid)
		  ||(a[n + i] >= mid && a[n + i + 1] >= mid)) return 1;
		if ((a[n - i] <  mid && a[n - i - 1] <  mid)
		  ||(a[n + i] <  mid && a[n + i + 1] <  mid)) return 0;
	}
	return a[1] >= mid;
}

int main()
{
	n = read();
	for (int i = 1; i <= n * 2 - 1; i++) a[i] = read();
	int l = 1, r = n * 2 - 1, ans = -1;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (check(mid)) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	printf("%d\n", ans);
	return 0;
}
