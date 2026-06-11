#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<pair<long long, long long> > prime_factorize(long long N) {
	vector<pair<long long, long long> > res;
	for (long long a = 2; a * a <= N; ++a) {
		if (N % a != 0) continue;
		long long ex = 0; // 指数

		 // 割れる限り割り続ける
		while (N % a == 0) {
			++ex;
			N /= a;
		}

		// その結果を push
		res.push_back({ a, ex });
	}

	// 最後に残った数について
	if (N != 1) res.push_back({ N, 1 });
	return res;
}

int main() {

	const ll mod = 1000000007;
	ll n; cin >> n;	
	map<ll, ll> mp;
	for (ll i = 1; i <= n; i++) {
		vector<pair<long long, long long>> a_prime;  // a^x ならば { a, x }
		a_prime = prime_factorize(i);
		for (ll i = 0; i < a_prime.size(); i++) {
			mp[a_prime[i].first] += a_prime[i].second;
		}
	}
	ll ans = 1;
	for (auto u : mp) {
		ans *= u.second + 1;
		ans %= mod;
	}
	cout << ans << endl;
    return 0;
}