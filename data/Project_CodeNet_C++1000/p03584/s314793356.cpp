#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	ll k;
	cin >> n >> k;
	vector<ll> a(n), b(n);
	rep(i,n) cin >> a[i] >> b[i];
	ll ans = 0;
	int r = 0;
	rep(i,n){
		bool ok = true;
		rep(j,32){
			if((a[i]>>j & 1) && !(k>>j & 1)) ok = false;
		}
		if(ok) ans += b[i];
	}
	ll tmp = 1;
	while(tmp <= k){
		ll ks = k;
		if(ks>>r & 1) ks = (k/tmp)*tmp - 1;
		ll score = 0;
		rep(i,n){
			bool ok = true;
			rep(j,32){
				if((a[i]>>j & 1) && !(ks>>j & 1)) ok = false;
			}
			if(ok) score += b[i];
		}
		++r;
		tmp *= 2;
		chmax(ans, score);
	}
	cout << ans << endl;
	return 0;
}