#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
	fast_io;
	ll n, l, t;
	cin >> n >> l >> t;
	ll cnt = 0;
	
	vector <ll> v;
	
	for(ll i = 0; i < n; i ++){
		ll x, w;
		cin >> x >> w;
		if(w == 1){
			v.pb((x + t) % l);
			if(l - x <= t){
				cnt += (t - l + x - 1) / l + 1;
			}
		}else{
			if(t > x)
				cnt -= (1 + (t - x - 1) / l);
				
			ll ind = (x - t) % l;
			
			while(ind < 0){
				ind += l;
			}
			v.pb(ind);
		}
	}
	
//	cout << cnt << endl;
	cnt %= n;
	sort(v.begin(), v.end());
	
	while(cnt < 0)
		cnt += n;
	
	for(ll i = cnt; i < n; i ++){
		cout << v[i] << endl;
	}
	for(ll i = 0; i < cnt; i ++){
		cout << v[i] << endl;
	}
	
	return 0;
}

