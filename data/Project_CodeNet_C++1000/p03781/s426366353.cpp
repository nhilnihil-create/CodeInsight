//#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

#define rep(i,n) for(ll (i)=0;(i)<(n);(i)++)
#define all(x) (x).begin(),(x).end()
#define MOD 1000000007
typedef long long ll;

using namespace std;


int main() {
	ll x; cin >> x;
	ll ans = 0;
	ll k = 0;
	while (k < x) {
		ans += 1;
		k += ans;
	}
	cout << ans << endl;
}