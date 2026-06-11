#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i = 0; i < (ll)(n); ++i)
#define FOR(i, a, b) for(ll i=(a); i < (ll)(b); ++i)
template<class T> inline bool chmax(T& a, T b) { if(a < b){ a=b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if(a > b){ a=b; return 1; } return 0;}

int main(){
	ll n,t,a;
	ll T=0,A=0;
	cin >> n;
	REP(i,n){
		cin >> t >> a;
		
		if(t >= T && a >= A){
			T = t;
			A = a;
		}else{
			ll tt=t*max(T/t, A/a);
			ll aa=a*max(T/t, A/a);
			while(tt < T || aa < A){
				tt += t;
				aa += a;
			}
			
			T = tt;
			A = aa;
		}
	}
	
	cout << T+A << endl;
	
	return 0;
}