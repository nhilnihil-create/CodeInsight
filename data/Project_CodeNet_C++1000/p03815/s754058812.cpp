#define rep(i, n) for(ll i = 0; i < n; i++)
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
	ll x;
	cin >> x;
	if (x<=6) cout << 1 << endl;
	else if (x<=11) cout << 2 << endl;
	else {
		ll p = x / 11;
		ll r = x % 11;
		if (r==0) cout << 2*p << endl;
		else if (r<=6) cout << 2*p+1 << endl;
		else cout << 2*p+2 << endl;
	}
	return 0;
}
