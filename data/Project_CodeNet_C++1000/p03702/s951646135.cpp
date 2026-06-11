#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  ll n, A, B; cin >> n >> A>> B;
	vector<ll> a(n);
	for(int i = 0; i < n; i++) scanf("%lld", &a[i]);
	ll left = 0, right = 1e9+2;
	while(right - left > 1){
		ll mid = (right + left) / 2, num = 0;
		for(int i = 0; i < n; i++) {
			ll x = a[i] - mid * B;
			if(x <= 0) continue;
			num += (x + A - B - 1) / (A - B);
		}
		if(num > mid) left = mid;
		else right = mid;
		//cout << left << endl;
	}
	cout << right << endl;
}