#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll n, c, k;
	cin >> n >> c >> k;
	vector<ll>t(n); //
	for (int i = 0; i < n; i++)cin >> t.at(i);
	sort(t.begin(), t.end());

	ll ans = 0;
	ll vac = c;
	ll ang = 0;
	for (int i = 0; i < n; i++) {
		ll x = t.at(i);
		if (ang < x) {
			ans++;
			vac = c - 1;
			ang = x + k;
		}
		else {
			if (vac == 0) {
				ans++;
				vac = c - 1;
				ang = x + k;
			}
			else vac--;
		}
		//cout << ans << " " << vac << " " << ang << endl;
	}
	cout << ans << endl;
}