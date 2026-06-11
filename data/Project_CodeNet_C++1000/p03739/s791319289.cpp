#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;
	vector<ll> a(n), tot(n), moto(n);
	rep(i, n) cin >> a[i];
	tot[0] = a[0];
	rep(i, n-1) tot[i+1] += tot[i] + a[i+1];
	
	ll ans = 1LL<<60, now = 0;
	ll wa = 0;
	int p;
	moto = tot;
	if(tot[0] != 0) {
		p = tot[0] / abs(tot[0]);
		rep(i, n) {
			tot[i] += wa;
			if(p == 1) {
				if(tot[i] <= 0) {
					wa += abs(tot[i]) + 1;
					now += abs(tot[i]) + 1;
				}
			} else {
				if(tot[i] >= 0) {
					wa -= abs(tot[i]) + 1;
					now += abs(tot[i]) + 1;
				}
			}
			// cout << tot[i] << " " << wa << endl;
			p *= -1;
		}
		ans = min(ans, now);
		tot = moto;
		p = tot[0] / abs(tot[0]) * -1;
		now = abs(tot[0])+ 1;
		wa = p * (abs(tot[0])+ 1);
		rep(i, n) {
			tot[i] += wa;
			if(p == 1) {
				if(tot[i] <= 0) {
					wa += abs(tot[i]) + 1;
					now += abs(tot[i]) + 1;
				}
			} else {
				if(tot[i] >= 0) {
					wa -= abs(tot[i]) + 1;
					now += abs(tot[i]) + 1;
				}
			}
			// cout << tot[i] << " " << wa << endl;
			p *= -1;
		}
		ans = min(ans, now);
	} else {
		tot = moto;
		now = 1;
		wa = 1;
		p = 1;
		rep(i, n) {
			tot[i] += wa;
			if(p == 1) {
				if(tot[i] <= 0) {
					wa += abs(tot[i]) + 1;
					now += abs(tot[i]) + 1;
				}
			} else {
				if(tot[i] >= 0) {
					wa -= abs(tot[i]) + 1;
					now += abs(tot[i]) + 1;
				}
			}
			// cout << tot[i] << " " << wa << endl;
			p *= -1;
		}
		ans = min(ans, now);
		tot = moto;
		now = 1;
		wa = -1;
		p = -1;
		rep(i, n) {
			tot[i] += wa;
			if(p == 1) {
				if(tot[i] <= 0) {
					wa += abs(tot[i]) + 1;
					now += abs(tot[i]) + 1;
				}
			} else {
				if(tot[i] >= 0) {
					wa -= abs(tot[i]) + 1;
					now += abs(tot[i]) + 1;
				}
			}
			// cout << tot[i] << " " << wa << endl;
			p *= -1;
		}
		ans = min(ans, now);
	}
	
	cout << ans << endl;
	return 0;
}