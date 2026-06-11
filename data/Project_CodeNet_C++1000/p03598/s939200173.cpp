#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll b[4][4];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n, k;
	cin >> n >> k;
	ll s = 0;
	for (int i = 0; i < n; i++)
	{
		ll a;
		cin >> a;
		s += min(a * 2, abs(k - a) * 2);
	}
	cout << s;
	return 0;
}
