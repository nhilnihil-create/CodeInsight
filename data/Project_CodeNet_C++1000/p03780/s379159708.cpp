#include <bits/stdc++.h>

long long *a{};
int n, k;

bool need(long long, long long, int, int);

int main()
{
	scanf("%d%d", &n, &k);
	a = new long long[n];
	for (int i = 0; i < n; i++) scanf("%lld", a + i);
	std::sort(a, a + n, std::greater<long long>());
	int left{-1}, right{n};
	while (left + 1 < right)
	{
		int mid{(left + right) / 2};
		if (need(k - a[mid], k, n - 1, mid)) left = mid;
		else right = mid;
	}
	printf("%d\n", n - left - 1);

	delete[] a;
	return 0;
}

bool need(long long left, long long right, int a_index, int ignore)
{
	if (left <= 0 && right > 0) return true;
	if (a_index == -1 || right <= 0) return false;

	if (a_index == ignore)
		return need(left, right, a_index - 1, ignore);
	// 連結なら連結したやつを渡す
	if (right - a[a_index] >= left)
		return need(left - a[a_index], right, a_index - 1, ignore);
	// 非連結なら[left, right)に
	return need(left, right, a_index - 1, ignore) || need(left - a[a_index], right - a[a_index], a_index - 1, ignore);
}
