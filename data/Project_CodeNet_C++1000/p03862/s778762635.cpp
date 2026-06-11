#include <algorithm>
#include <cmath>
#include <vector>
#include <functional>
#include <cstdlib>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <ctype.h>
#include <climits>
#include <queue>
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i = 0; i < (ll)(n); ++i)
#define FOR(i, a, b) for(ll i=(a); i < (ll)(b); ++i)
template<class T> inline bool chmax(T& a, T b) { if(a < b){ a=b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if(a > b){ a=b; return 1; } return 0;}

int main(){
	ll n,x;
	cin >> n >> x;
	vector<ll> a(n);
	REP(i,n) cin >> a[i];
	
	ll ans = 0;
	REP(i,n-1){
		if(a[i]+a[i+1] > x){
			ll diff = a[i]+a[i+1] - x;
			if(diff <= 0) continue;
			ans += diff;
			if(diff <= a[i+1]){
				a[i+1] -= diff;
			}else{
				a[i] -= diff - a[i+1];
				a[i+1] = 0;
			}
		}
	}
	
	cout << ans << endl;
	
	return 0;
}