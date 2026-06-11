#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n, x[N], l, q, le, ri, a, b, f[N][35];

long long sum;

void init ()
{
	scanf ( "%d" , &n);
	for (int i = 1; i <= n; ++ i)
		scanf ( "%d" , &x[i]);
	scanf ( "%d%d" , &l, &q);
}

void work ()
{
	for (int i = 1; i <= n; ++ i)
	{
		le = i + 1, ri = n;
		for (; le <= ri; )
		{
			int mid = (le + ri) >> 1;
			if (x[mid] <= l + x[i])
				le = mid + 1;
			else ri = mid - 1;
		}
		if (x[i] + l >= x[n])
			f[i][0] = n;
		else f[i][0] = le - 1;
	}
	for (int i = 1; i <= 31; ++ i)
		for (int j = 1; j <= n; ++ j)
			f[j][i] = f[ f[j][i - 1] ][i - 1];
}

void prin ()
{
	for (int i = 1; i <= q; ++ i)
	{
		scanf ( "%d%d", &a, &b);
		if (b < a) swap (a, b);
		sum = 0;
		for (int j = 31; j >= 0; -- j)
			if (f[a][j] < b)
			{
				sum += (1 << j);
				a = f[a][j];
			}
		printf ( "%lld\n" , sum + 1);
	}
}

int main ()
{
	init ();
	work ();
	prin ();
	return 0;
}