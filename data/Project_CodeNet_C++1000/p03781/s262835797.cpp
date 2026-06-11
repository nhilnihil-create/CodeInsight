#include "bits/stdc++.h"

typedef long long ll;
#define rep(i, n) for(ll i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
ll x;
signed main() {
	cin >> x;
	ll ans = 0;
	rep(i,1000000) {
		ans += i;
		if (ans >= x) {
			cout << i << endl;
			break;
		}
	}
}
