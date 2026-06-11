#include<iostream>
#include<string>
#include<map>
using namespace std;
typedef long long ll;
const int Max = 1e5 + 5;
int lst[Max];

int main()
{
	ll x, y;
	cin >> y >> x;
	ll res = 1e18+5;
	for (int i = 1;i <= x - 1;i++)
	{
		ll a = (x - i) * y;
		ll b = i * (y / 2);
		ll c = x * y - a - b;
		res = min(res, max(a, max(b, c)) - min(a, min(b, c)));
		a = i * y;
		b = (x - i) / 2 * y;
		c = x * y - a - b;
		res = min(res, max(a, max(b, c)) - min(a, min(b, c)));
	}
	for (int i = 1;i <= y - 1;i++)
	{
		ll a = (y - i) * x;
		ll b = i * (x / 2);
		ll c = x * y - a - b;
		res = min(res, max(a, max(b, c)) - min(a, min(b, c)));
		a = i * x;
		b = (y - i) / 2 * x;
		c = x * y - a - b;
		res = min(res, max(a, max(b, c)) - min(a, min(b, c)));
	}
	cout << res;
}