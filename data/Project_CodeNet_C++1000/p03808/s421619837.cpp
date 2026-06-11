#include <bits/stdc++.h>
typedef long long ll; 
 
using namespace std;

int main() {
	ll N;
	cin >> N;
	vector<ll> a(N);
	ll sum = 0;
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
		sum += a[i];
	}

	bool can = true;
	ll x = N*(N + 1) / 2;
	if (sum % x != 0) { can = false; }

	ll n = sum / x;
	ll cnt = 0;
	for (int i = 0; i < N; ++i) {
		ll diff = a[i] - a[(i - 1 + N) % N] - n;
		if ((diff > 0) || (diff % N != 0)) {
			can = false;
		} else {
			cnt += abs(diff / N);
		}
	}
	if (cnt != n) { can = false; }

	if (can) { cout << "YES" << endl; }
	else { cout << "NO" << endl; }

	return 0;
}
