#define rep(i, n) for(ll i = 0; i < n; i++)
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
	ll n;
	cin >> n;
	vector<ll> a(n);
	rep(i,n) cin >> a[i];
	sort(a.begin(), a.end(), greater<ll>());
	ll tate = 0;
	ll yoko = 0;
	ll idx_tate = 0;
	bool flag_tate = false;
	rep(i,n-1) {
		if (a[i] == a[i+1]) {
			if (!flag_tate) {
				tate = a[i];
				i++;
				flag_tate = true;
			}
			else {
				yoko = a[i];
				break;
			}
		}
	}
	cout << tate*yoko << endl;
	return 0;
}
