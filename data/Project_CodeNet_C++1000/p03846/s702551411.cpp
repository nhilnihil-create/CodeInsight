#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i = 0; i < (ll)(n); ++i)
#define FOR(i, a, b) for(ll i=(a); i < (ll)(b); ++i)
template<class T> inline bool chmax(T& a, T b) { if(a < b){ a=b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if(a > b){ a=b; return 1; } return 0;}
 
int a[100000];
 
int main(){
	int n,in;
	cin >> n;
	REP(i,n){
		cin >> in;
		
		if(n%2 == in%2){
			cout << 0 << endl;
			return 0;
		}
		if(in==0 && a[in] >= 1){
			cout << 0 << endl;
			return 0;
		}
		if(a[in] >= 2){
			cout << 0 << endl;
			return 0;
		}else{
			a[in]++;
		}
		
	}
	
	const ll mod = 1000000007;
	ll ans = 1;
	REP(i,n/2){
		ans = (ans*2)%mod;
	}
	cout << ans << endl;
	
	return 0;
}