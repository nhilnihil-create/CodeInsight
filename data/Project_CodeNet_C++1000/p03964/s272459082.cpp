#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long ul;

int main()
{
	ll n, a, b, x, y;
	cin >> n;
	cin >> a >> b;
	for (int i = 1; i < n; i++)
	{
		cin >> x >> y;
		ll r1 = a / x, r2 = b / y;
		if (a % x)
			r1++;
		if (b % y)
			r2++;
		ll k = max(r1, r2);
		x *= k;
		y *= k;
		a = x;
		b = y;
	}
	cout << b + a << endl;
	return 0;
}
