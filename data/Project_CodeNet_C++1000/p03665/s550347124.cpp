#include<iostream>
#include<string>
#include<algorithm>    
#include<cmath>
#include<map>
#include<vector>
#include<math.h>
#include<stdio.h>
#include<stack>
#include<queue>
#include<tuple>
#include<cassert>
#include<set>
#include<functional>
//#include<bits/stdc++.h>
#define rep(i, x) for(ll i = 0; i < x; i++)
#define all(a) (a).begin(),(a).end()
using ll = long long;
using ld = long double;
using namespace std;
const ll INF = 1000000000000000000;
const ll mod = 1000000007;
const ld pi = 3.141592653589793238;

ll a[1234];
signed main() {
	ll n, p; cin >> n >> p;
	rep(i, n) {
		cin >> a[i];
	}
	ll gu1 = 0, ki1 = 0, gu2 = 0, ki2 = 0, gu3 = 0, ki3 = 0;
	ll flag = n / 3, kari1 = 0, kari2 = 0;
	for (int h = 0; h < (1 << flag); h++) {
		ll cnt = 0;
		for (ll i = 0; i <= flag - 1; i++) {
			if ((h & (1 << i)) > 0) {
				cnt += a[i]; cnt %= 2;
				kari1 = max(kari1, i);
			}
		}
		if (cnt % 2 == 0) { gu1++; }
		else { ki1++; }
	}
	kari1++;
	flag = (n + 1) / 3;
	for (int h = 0; h < (1 << flag); h++) {
		ll cnt = 0;
		for (int i = 0; i <= flag - 1; i++) {
			if ((h & (1 << i)) > 0) {
				cnt += a[kari1 + i]; cnt %= 2;
				kari2 = max(kari2, kari1 + i);
			}
		}
		if (cnt % 2 == 0) { gu2++; }
		else { ki2++; }
	}
	flag = (n + 2) / 3;
	for (int h = 0; h < (1 << flag); h++) {
		ll cnt = 0;
		for (int i = 0; i <= flag - 1; i++) {
			if ((h & (1 << i)) > 0) {
				cnt += a[kari2 + i]; cnt %= 2;
			}
		}
		if (cnt % 2 == 0) { gu3++; }
		else { ki3++; }
	}
	ll ans = 0;
	if (p == 0) {
		ans += (gu1 * gu2 * gu3);
		ans += (gu1 * ki2 * ki3);
		ans += (ki1 * gu2 * ki3);
		ans += (ki1 * ki2 * gu3);
		cout << ans << endl;
	}
	else {
		ans += (gu1 * gu2 * ki3);
		ans += (gu1 * ki2 * gu3);
		ans += (ki1 * gu2 * gu3);
		ans += (ki1 * ki2 * ki3);
		cout << ans << endl;
	}
	return 0;
}