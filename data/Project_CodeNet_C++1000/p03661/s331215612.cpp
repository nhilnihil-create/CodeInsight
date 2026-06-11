#include<iostream>
using namespace std;

typedef long long ll;

const int maxn = 1000000 + 10;
const ll INF = 100000000000;

int a[maxn];

ll Abs(ll x)
{
	return x > 0 ? x : -x;
}

int main()
{
	ll x, y;
	y = 0;
	x = 0;
	ll n;
	cin >> n;
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
		y += a[i];
	}

	ll min = INF;
	
	for (int i = 0; i < n - 1; i++) {
		x += a[i];
		y -= a[i];
		if (Abs(x - y) < min) min = Abs(x - y);
	}

	cout << min;

	return 0;
}