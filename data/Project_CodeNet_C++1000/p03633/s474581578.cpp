#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;
	vector<ll>t(n);
	for (int i = 0; i < n; i++)cin >> t.at(i);
	ll ans = t.at(0);
	for (int i = 1; i < n; i++) {
		ans = ans / __gcd(ans, t.at(i)) * t.at(i);
	}
	cout << ans << endl;
}