#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

ll gcd(ll x, ll y)
{
	if (y == 0) return x;
	return gcd(y, x % y);
}

signed main(void)
{
	int n, k;
	vector<int> v;
	ll g;
	
	cin >> n >> k;
	rep(i, n)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	g = v[0];
	rep(i, n)
	{
		g = gcd(g, v[i]);
	}
	if (k <= v[n - 1] && k % g == 0)
		cout << "POSSIBLE" << endl;
	else
		cout << "IMPOSSIBLE" << endl;
	return 0;
}
