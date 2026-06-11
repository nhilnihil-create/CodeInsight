#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i = 0; i < (ll)(n); ++i)
#define FOR(i, a, b) for(ll i=(a); i < (ll)(b); ++i)
template<class T> inline bool chmax(T& a, T b) { if(a < b){ a=b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if(a > b){ a=b; return 1; } return 0;}

ll func(ll x, ll y){
	ll a,b,c,ret;
	a = (x/3)*y;
	if(y%2==0){
		b = (x-x/3)*(y/2);
		c = b;
	}else{
		b = (x-x/3)*(y/2);
		c = (x-x/3)*(y/2+1);
	}
	ret = max(a,max(b,c)) - min(a,min(b,c));
	
	a = (x/3+1)*y;
	if(y%2==0){
		b = (x-x/3-1)*(y/2);
		c = b;
	}else{
		b = (x-x/3-1)*(y/2);
		c = (x-x/3-1)*(y/2+1);
	}
	chmin(ret,max(a,max(b,c)) - min(a,min(b,c)));
	return ret;
}

int main(){
	ll h,w;
	cin >> h >> w;
	
	if(h%3==0 || w%3==0){
		cout << 0 << endl;
		return 0;
	}
	
	ll ans;
	ans = min(h,w);
	chmin(ans, func(h,w));
	chmin(ans, func(w,h));
	
	cout << ans << endl;
	
	return 0;
}