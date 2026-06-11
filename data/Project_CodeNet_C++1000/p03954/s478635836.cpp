#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	for (; ch < '0' || ch > '9'; ch = getchar()) if (ch == '-') f = -1;
	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = (x << 1) + (x << 3) + ch - '0';
	return x * f;
}

const int N = 2e5 + 5;
int a[N], n;

bool check(int k)
{
	for (int i = 0; i < n - 1; ++i)
	{
		if (a[n + i] > k && a[n + i + 1] > k) return 0;
		if (a[n - i] > k && a[n - i - 1] > k) return 0;
		if (a[n + i] <= k && a[n + i + 1] <= k) return 1;
		if (a[n - i] <= k && a[n - i - 1] <= k) return 1;
		
	}
	return a[1] <= k && a[2 * n - 1] <= k;
}

int main()
{
	n = read();
	for (int i = 1; i <= 2 * n - 1; ++i) a[i] = read();
	
	int l = 1, r = 2 * n - 1;
	while (l < r)
	{
		int mid = l + r >> 1;
		if (check(mid)) r = mid;
			else l = mid + 1;
	}
	printf("%d\n", l);
	
	return 0;
}
