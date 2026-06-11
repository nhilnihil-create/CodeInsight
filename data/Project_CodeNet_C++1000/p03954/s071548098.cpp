#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 200010;

int n;
int a[N];
bool st[N];

bool check(int x)
{
	int mi = 2 * n - 1;
	bool res;
	for (int i = 1; i <= 2 * n - 1; i++)
	{
		if (a[i] >= x) st[i] = true;
		else st[i] = false;
		if (st[i] != st[i - 1]) continue;

		if (i <= n)
		{
			if (n - i < mi)
			{
				mi = n - i;
				res = st[i];
			}
		}
		else
		{
			if ((i - 1) - n < mi)
			{
				mi = i - 1 - n;
				res = st[i];
			}
		}
	}

	if (mi > n)
	{
		res = st[1];
	}

	return res;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= 2 * n - 1; i++)
	{
		scanf("%d", &a[i]);
	}

	int l = 0, r = 0x3f3f3f3f;
	while (l < r)
	{
		int mid = (l + r + 1) >> 1;
		if (check(mid)) l = mid;
		else r = mid - 1;
	}
	printf("%d", r);
}