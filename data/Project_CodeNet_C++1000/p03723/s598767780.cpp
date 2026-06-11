#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll a, b, c;
	cin >> a >> b >> c;
	ll ct = 0;
	while (a % 2 == 0 && b % 2 == 0 && c % 2 == 0)
	{
		ll au = b / 2 + c / 2;
		ll bu = a / 2 + c / 2;
		ll cu = a / 2 + b / 2;
		if (au == a && bu == b && cu == c)
		{
			cout << -1;
			return 0;
		}
		else
		{
			a = au;
			b = bu;
			c = cu;
			ct++;
		}
	}
	cout << ct;
	return 0;
}
