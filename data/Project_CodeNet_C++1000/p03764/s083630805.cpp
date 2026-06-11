#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

ll add(ll a, ll b) {
	return ((a%mod) + (b%mod)) % mod;
}


ll sub(ll a, ll b) {
	return ((a%mod) - (b%mod) + mod) % mod;
}


ll mul(ll a, ll b) {
	return ((a%mod)*(b%mod)) % mod;
}


int main() {
	int n, m;
	cin >> n >> m;
	vector<ll> X, Y;
	ll totalX = 0, totalY = 0;
	for (int i = 0; i < n; i++) {
		ll x;
		cin >> x;
		X.push_back(x);
		totalX += x;
	}
	for (int i = 0; i < m; i++) {
		ll y;
		cin >> y;
		Y.push_back(y);
		totalY += y;
	}
	ll ans = 0;
	ll sumX = 0;
	sort(X.rbegin(), X.rend());
	sort(Y.rbegin(), Y.rend());
	for (int i = 0; i < n; i++) {
		sumX = add(sumX, sub(mul(n - i, X[i]), totalX));
		totalX -= X[i];
	}
	for (int i = 0; i < m; i++) {
		ll b = sub(mul(m - i, Y[i]), totalY);
		ans = add(ans, mul(sumX, b));
		totalY -= Y[i];
	}
	cout << ans;




}