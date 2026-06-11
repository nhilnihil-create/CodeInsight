#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ll w, h; cin >> w >> h;
	vector<pair<ll, bool> > v;
	for(ll i = 0; i < w + h; ++i){
		ll p; cin >> p;
		v.push_back(pair<ll, bool>(p, i < w));
	}
	ll ans = 0;
	ll po[] = {w + 1, h + 1};
	sort(v.begin(), v.end());
	for(auto e : v){
		ans += e.first * max<ll>(0, po[(int)e.second]);
		--po[(int)!e.second];
	}
	cout << ans << endl;
	return 0;
}