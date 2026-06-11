#include <bits/stdc++.h>
#define rep(i, n) for(long long i = 1; i < (n); i++)
using namespace std;
typedef long long ll;

ll f(ll x, ll y)
{
	ll a, b, c;
	ll S = x * y;
	ll ans = 1e18; 
	rep(i, x)
	{
		a = i * y; 
		b = (x - i) / 2 * y;
		c = S - a - b;
		ll tmp = max(max(a, b), c) - min(min(a, b), c);
		ans = min(ans, tmp);
		b = (S - a) / (x - i) / 2 * (x - i);
		c = S - a - b;
		tmp = max(max(a, b), c) - min(min(a, b), c);
		ans = min(ans, tmp);
	}
	return ans;
}

signed main(void)
{
	ll h, w;
	cin >> h >> w;
	cout << min(f(h, w), f(w, h)) << endl;
	return 0;
}
