#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll a, b, c;
	cin >> a >> b >> c;
	if (a % 2 == 0 || b % 2 == 0 || c % 2 == 0)cout << 0 << endl;
	else {
		ll ab = a * b;
		ll bc = b * c;
		ll ca = c * a;
		ll ans = min(ab, min(bc, ca));
		cout << ans << endl;
	}
}