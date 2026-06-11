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
	
	ll n; cin >> n;
	const ll mod = 1000000007;
	vector<ll> num(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		vector<pair<long long, long long>> a_prime;  // a^x ならば { a, x }
		a_prime = prime_factorize(i);
		for (int j = 0; j < a_prime.size(); j++) {
			num[a_prime[j].first] += a_prime[j].second;
			num[a_prime[j].first] %= mod;
		}
	}
	ll ans = 1;
	for (int i = 1; i <= n; i++) {
		ans *= num[i] + 1;
		ans %= mod;
	}
	cout << ans << endl;
	return 0;
}