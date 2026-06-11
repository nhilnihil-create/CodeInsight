#include <iostream>
using namespace std;
#define ll long long
int n;
ll a, b, h[100009];

bool sc(ll l)
{
	ll r = 0;
	for (int i = 0; i < n; i++) {
		ll th = h[i] - (b * l);
		if (th > 0)
			r += (th - 1) / (a - b) + 1;
	}
	return (r <= l);
}

ll bs(ll s, ll e)
{
	ll md = (s + e) / 2;
	if (s >= e) return md;
	if (sc(md)) return bs(s, md);
	else return bs(md + 1, e);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> a >> b;
	for (int i = 0; i < n; i++)
		cin >> h[i];
	cout << bs(0, 1000000009LL) << '\n';
	return 0;
}