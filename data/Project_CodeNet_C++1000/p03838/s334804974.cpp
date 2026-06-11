#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ll x, y;
	cin >> x >> y;
	ll ans = 1e10;
	ll dif = y - x;
	if (dif >= 0) {
		ans = min(ans, dif);
	}
	else {
		ans = min(ans, -dif + 2);
	}
	ll absdif = abs(abs(x) - abs(y));
	if (x * y <= 0)ans = min(ans, absdif + 1);
	cout << ans << endl;
}