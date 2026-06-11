// ABC 052 C

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<pair<ll, ll>> prime_factori(ll n) {
	vector<pair<ll, ll>> res;

	for(ll i = 2; i * i <= n; ++i) {
		if(n % i != 0) continue;

		ll exp = 0;
		while(n % i == 0) {
			++exp;
			n /= i;
		}
		res.push_back({i, exp});
	}

	if(n != 1) res.push_back({n, 1});

	return res;
}


int main()
{

	const int MOD = pow(10, 9) + 7;	

	ll n;
	cin >> n;

	vector<ll> ex(n+1, 0);
	for(int i = 2; i <= n; ++i) {
		const auto &pf = prime_factori(i);
		for(auto item : pf) ex[item.first] += item.second;
	}

	ll ans = 1;
	for(int i = 2; i <=n; ++i) {
		ans *= ex[i] + 1;
		ans %= MOD;
	}

	cout << ans << "\n";

	return 0;
}