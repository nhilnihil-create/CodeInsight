#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 100010;

int n, a[N << 1];

bool check(int x)
{
	int l = n, r = n;
	while (l > 1 && (a[l - 1] >= x) != (a[l] >= x)) --l;
	while (r < 2 * n - 1 && (a[r + 1] >= x) != (a[r] >= x)) ++r;
	if (l == 1 && r == 2 * n - 1) return (a[n] >= x) ^ ((n + 1) & 1);
	if (l == 1) return a[r] >= x;
	if (r == 2 * n - 1) return a[l] >= x;
	if (n - l <= r - n) return a[l] >= x;
	return a[r] >= x;
}

int main()
{
	int l = 0x7fffffff, r = 0;
	
	scanf("%d", &n);
	
	for (int i = 1; i <= 2 * n - 1; ++i)
	{
		scanf("%d", a + i);
		l = min(l, a[i]);
		r = max(r, a[i]);
	}
	
	while (l < r)
	{
		int mid = (0ll + l + r + 1) >> 1;
		if (check(mid)) l = mid;
		else r = mid - 1;
	}
	
	cout << l;
	
	return 0;
}