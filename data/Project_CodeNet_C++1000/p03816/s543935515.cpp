//#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

#define rep(i,n) for(ll (i)=0;(i)<(n);(i)++)
#define all(x) (x).begin(),(x).end()
#define MOD 1000000007
typedef long long ll;

using namespace std;

int main() {
	ll n;
	cin >> n;
	vector<ll> v(n);
	rep(i, n) {
		cin >> v[i];
	}
	sort(all(v));
	ll ans = n;
	rep(i, n - 1) {
		//cout << i << " " << v[i] << endl;
		if (v[i] == v[i + 1]) {
			ans -= 1;
		}
	}
	if (ans % 2 == 0) ans -= 1;
	cout << ans << endl;

}