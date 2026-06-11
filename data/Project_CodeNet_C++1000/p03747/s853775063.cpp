#include <bits/stdc++.h>

const int N = 100005;

int read()
{
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
	while (ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}

int a[N],b[N];

int main()
{
	int n = read(), L = read(), T = read();
	int s = 1;
	for (int i = 1; i <= n; i++)
	{
		int x = read(), w = read();
		if (w == 1)
		{
			a[i] = (x + T) % L;
			if (T >= L - x)
				(s -= (T - L + x) / L + 1) %= n;
		}
		else
		{
			a[i] = ((x - T) % L + L) % L;
			if (T >= x + 1)
				(s += (T - x - 1) / L + 1) %= n;
		}
	}
	s = (s % n + n - 1) % n + 1;
	std::sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		b[(s + i - 2) % n + 1] = a[i];
	for (int i = 1; i <= n; i++)
		printf("%d\n",b[i]);
}