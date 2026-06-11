#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i = 0; i < (ll)(n); ++i)
#define FOR(i, a, b) for(ll i=(a); i < (ll)(b); ++i)
template<class T> inline bool chmax(T& a, T b) { if(a < b){ a=b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if(a > b){ a=b; return 1; } return 0;}

int main(){
	ll n,a,b;
	cin >> n >> a >> b;
	vector<ll> x(n);
	REP(i,n) cin >> x[i];
	
	ll ans = 0;
	for(int i=0; i<n-1; i++){
		ans += min((x[i+1]-x[i])*a, b);
	}
	
	cout << ans << endl;
	
	return 0;
}