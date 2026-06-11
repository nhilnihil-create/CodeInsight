#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main() {

	ll n; cin >> n;
	ll add = 0;
	ll tmp = 10000000000;
	ll minIndex;
	for (ll i = 0; i < n; i++) {
		ll a, b; cin >> a >> b;
		if (chmin(tmp, b)) {
			minIndex = a;
		}
	}
	cout << minIndex + tmp << endl;
    return 0;
}