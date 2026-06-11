#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<(ll)n;++i)
using P = pair<ll,ll>;

ll paw( ll x, ll n ){
	if( n == 0 ) return 1;
	ll t = pow(x,n/2);
	if( n%2 == 0 ){
		return t*t;
	}else{
		return t*t*x;
	}
}

int main() {
	ll n,p;cin >> n >> p;
	ll even = 0;
	ll odd = 0;
	rep(i,n){
		ll num;cin >> num;
		if( num%2 == 0 ) even++;
		else odd++;
	}
	if( p == 0 ){
		ll ans = paw(2,even)*paw(2,odd);
		if( ans == 1 ) cout << 1 << endl;
		else if( odd == 0 ){
			cout << ans << endl;
		}else{
			cout << ans/2 << endl;
		}
	}else{
		if( odd == 0 ){
			cout << 0 << endl;
		}else{
			cout << paw(2,even)*paw(2,odd)/2 << endl;
		}
	}
	return 0;
}