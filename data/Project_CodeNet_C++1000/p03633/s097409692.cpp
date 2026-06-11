#include<bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define repk(i,k,n) for (ll i = k; i < (ll)(n); ++i)
#define MAt 500000001000000000
#define MOD 1000000007
typedef long long  ll;

using namespace std;

// 最大公約数のll版
ll gcd(ll a, ll b) {
	if (a < b) swap(a, b);
	return b == 0 ? a : gcd(b, a%b);
}

// 最小公倍数のll版
ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	ll ans = 1;

	rep(i,N){
		ll t;
		cin >> t;

		ans = lcm(max(ans,t),min(ans,t));
	}

	cout << ans << endl;

	return 0;
}