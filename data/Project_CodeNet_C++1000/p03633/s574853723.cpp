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
#include <iomanip>
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i = 0; i < (ll)(n); ++i)
#define FOR(i, a, b) for(ll i=(a); i < (ll)(b); ++i)
template<class T> inline bool chmax(T& a, T b) { if(a < b){ a=b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if(a > b){ a=b; return 1; } return 0;}

ll GCD(ll a, ll b){
	if(b==0) return a;
	
	return GCD(b, a%b);
}

int main(){
	int n;
	cin >> n;
	vector<ll> t(n);
	REP(i,n) cin >> t[i];
	
	ll ans = 0;
	ans = t[0];
	FOR(i,1,n){
		ans = (ans/GCD(ans,t[i])) * t[i];
	}
	
	cout << ans << endl;
	
	return 0;
}