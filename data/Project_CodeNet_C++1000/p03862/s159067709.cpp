#include<bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define repk(i,k,n) for (ll i = k; i < (ll)(n); ++i)
#define MAX 500000001000000000
#define MOD 1000000007
typedef long long  ll;

using namespace std;

ll ans,cnt;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll N,x;
	cin >> N >> x;

	vector<ll> a(N);
	rep(i, N) {
		cin >> a[i];
		if (a[i] > x) {
			ans += a[i] - x;
			a[i] = x;
		}
	}

	for (ll i = 1; i <= N - 1; i++) {
		if (a[i - 1] + a[i] > x) {
			ans += (a[i - 1] + a[i]) - x;
			a[i] = x - a[i - 1];
		}
	}

	cout << ans << endl;

	return 0;
}