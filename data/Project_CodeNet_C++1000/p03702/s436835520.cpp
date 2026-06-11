#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
	ll n, a, b; scanf("%lld%lld%lld", &n, &a, &b);
	vector<ll> h(n);
	for(int i = 0; i < n; i++){
		scanf("%lld", &h[i]);
	}
	ll low = 0, high = 1e9 + 2;
	while(high - low > 1){
		vector<ll> h1 = h;
		ll mid = (high + low) / 2;
		for(int i = 0; i < n; i++){
			h1[i] = max(0LL, h[i] - b * mid);
		}
		ll num = 0;
		for(int i = 0; i < n; i++){
			num += (h1[i] + a - b - 1) / (a - b);
		}
		if(num > mid) low = mid;
		else high = mid;
	}
	cout << high << endl;
}