#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n, sum = 0, cnt1 = 0, cnt2 = 0;
	cin >> n;
	vector<ll> v(2 * n);
	for (ll i = 0; i < 2 * n; i++) {
		cin >> v.at(i);
	}
	sort(v.begin(), v.end(), greater<ll>());
	while (cnt1 < n) {
		cnt2++;
		sum += v[cnt2];
		cnt2++;
		cnt1++;
	}
	cout << sum << endl;
	return 0;
}
