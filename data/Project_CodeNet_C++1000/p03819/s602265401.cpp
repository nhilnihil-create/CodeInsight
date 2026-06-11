#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

inline int getint()
{
	static char c;
	while ((c = getchar()) < '0' || c > '9');

	int res = c - '0';
	while ((c = getchar()) >= '0' && c <= '9')
		res = res * 10 + c - '0';
	return res;
}

const int MaxN = 300000;
const int MaxM = 100000;

int n, m;
int sum[MaxM + 2];

struct interval
{
	int l, r;
	interval() {}
	interval(const int &_l, const int &_r)
		: l(_l), r(_r) {}

	inline int length() const
	{
		return r - l + 1;
	}

	friend inline bool operator<(const interval &lhs, const interval &rhs)
	{
		return lhs.r - lhs.l < rhs.r - rhs.l;
	}
};
interval a[MaxN];

int bit[MaxM + 2];

void bit_add(int x, int d)
{
	for (int i = ++x; i <= m + 2; i += i & -i)
		bit[i] += d;
}

int bit_query(int x)
{
	int res = 0;
	for (int i = ++x; i; i ^= i & -i)
		res += bit[i];
	return res;
}

int main()
{
	cin >> n >> m;

	sum[1] = n;
	for (int i = 0; i < n; ++i)
	{
		a[i].l = getint();
		a[i].r = getint();
		--sum[min(m, a[i].r - a[i].l + 1) + 1];
	}

	for (int i = 2; i <= m; ++i)
		sum[i] += sum[i - 1];

	sort(a, a + n);

	int cur = 0;
	for (int i = 1; i <= m; ++i)
	{
		for (int k = 0; k <= m; k += i)
			sum[i] += bit_query(k);

		printf("%d\n", sum[i]);

		while (cur < n && a[cur].length() == i)
		{
			bit_add(a[cur].l, 1);
			bit_add(a[cur].r + 1, -1);
			++cur;
		}
	}

	return 0;
}