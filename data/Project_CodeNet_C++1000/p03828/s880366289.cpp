#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod = 1000000007;

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

int main()
{
	ll n; cin >> n;
	
	vector<ll> primeNum(1000,0);

	for (ll i = 2; i <= n ; i++) {

		vector<pair<ll, ll>> i_prime;		
		i_prime = prime_factorize(i);

		ll tmp_ans = 1;
		for (ll j = 0; j < i_prime.size(); j++) {
			primeNum[i_prime[j].first] += i_prime[j].second;
		}
	
	}

	ll ans = 1;
	for (ll i = 2; i <= 1000; i++) {
		ans *= primeNum[i] + 1;
        ans = ans % mod;
	}
	
	cout << ans << endl;
	return 0;
}