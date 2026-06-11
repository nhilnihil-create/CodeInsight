#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int a[2 * N];

int check(int x, int k)
{
	if (x >= k) return 1;
	return 0;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < 2 * n - 1; i++)
	{
		cin >> a[i];
	}
	int l = 1, r = 2 * n;
	while (r - l > 1)
	{
		int mid = (l + r) / 2;
		int f = 0, ans = 0;
		int indx = n - 1;
		for (int i = 1; i <= n - 1; i++)
		{
			if (check(a[indx + i], mid) == check(a[indx + i - 1], mid))
			{
				f = 1;
				ans = check(a[indx + i], mid);
				break;
			}
			if (check(a[indx - i], mid) == check(a[indx - i + 1], mid))
			{
				f = 1;
				ans = check(a[indx - i], mid);
				break;
			}
		}
		if (!f)
		{
			if (n % 2 == 0)
			{
				ans = 1 - check(a[indx], mid);
			}
			else
			{
				ans = check(a[indx], mid);
			}
		}
		if (ans == 1)
		{
			l = mid;
			continue;
		}
		r = mid;
	}
	cout << l;
}
