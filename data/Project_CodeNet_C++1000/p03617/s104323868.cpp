#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	long long q, h, s, d, n;
	cin >> q >> h >> s >> d >> n;
	n *= 100;

	long long ans = 0;
	long long t = n / 200;
	n -= t * 200;
	ans += min(min(t * d, 2 * t * s), min(4 * t * h, 8 * t * q));

	t = n / 100;
	n -= t * 100;
	ans += min(t * s, min(2 * t * h, 4 * t * q));

	t = n / 50;
	n -= t * 50;
	ans += min(t * h, 2 * t * q);

	t = n / 25;
	n -= t * 25;
	ans += t * q;

	cout << ans << endl;

	return 0;
}