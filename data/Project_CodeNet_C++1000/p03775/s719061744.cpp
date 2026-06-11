#include<bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define repk(i,k,n) for (ll i = k; i < (ll)(n); ++i)
#define MOD 1000000007
typedef long long  ll;

using namespace std;

/* 約数の列挙(O(√N)) */
vector<ll> enum_divisors(ll N) {
	vector<ll> res;
	for (ll i = 1; i * i <= N; ++i) {
		if (N % i == 0) {
			res.push_back(i);
			// 重複しないならば i の相方である N/i も push
			if (N / i != i) res.push_back(N / i);
		}
	}
	// 小さい順に並び替える
	sort(res.begin(), res.end());
	return res;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll n;
	cin >> n;

	vector<ll> vec = enum_divisors(n);

	ll half = vec[(vec.size() - 1) / 2];
	ll ans;
	if (vec.size() % 2 == 0) {
		ans = log10(max(half, n / half)) + 1;
	}
	else {
		ans = log10(half) + 1;
	}
	cout << ans << endl;

	return 0;
}