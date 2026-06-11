#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long int q, h, s, d;
	long double n;
	cin >> q >> h >> s >> d >> n;
	long long int ans = 0;
	if (h >= 2 * q)
	{
		h = 2 * q;
	}
	if (s >= 2 * h)
	{
		s = 2 * h;
	}
	if (d >= 2 * s)
	{
		d = 2 * s;
	}
	while (n != 0)
	{
		if (n >= 2)
		{
			ans += (int)(n / 2)* d;
			n = (int)(n)%2;
		}
		if (n >= 1)
		{
			ans += s;
			n -= 1;
		}
		if (n >= 0.5)
		{
			ans += (n / 2)* d;
			n -= 0.5;
		}
		if (n >= 0.25)
		{
			ans += (n / 2)* d;
			n -= 0.25;
		}
	}
	cout << ans << endl;
	return 0;
}