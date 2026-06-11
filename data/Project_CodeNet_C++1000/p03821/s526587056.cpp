#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(int argc, char **argv)
{
	ll n; cin >> n;
	vector<ll> a(n), b(n);
	for (ll i = 0; i < n; ++i)
		cin >> a[i] >> b[i];

	ll res{0};
	for (ll i = n-1; i >= 0; --i)
	{
		a[i] += res;
		if (a[i] % b[i] == 0) continue;
		res += b[i] - (a[i] % b[i]);
	}
	std::cout << res << std::endl;
}
