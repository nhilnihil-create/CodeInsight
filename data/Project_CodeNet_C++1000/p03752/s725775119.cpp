#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(ll i = 0; i<(ll)(n); i++)
#define REPS(i,n) for (ll i = 1; i<=(ll)(n); i++)
#define REPD(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)
#define pb push_back
#define MOD 1000000007
#define MOD2 998244353

int main(){
	ll n, k; cin >> n >> k;
	vector<ll> a(n); REP(i,n) cin >> a.at(i);
	ll ans = 100000000000;
	REP(i,(1<<n)){
		ll maxh = 0; ll cntcolor = 0; ll cnt = 0;
		REP(j,n){
			if ((i>>j)%2==1){
				cntcolor++;
				if (a.at(j)>maxh){
					maxh = a.at(j);
				}
				else {
					maxh++;
					cnt += maxh-a.at(j);
				}
			}
			else{
				if (a.at(j)>maxh) maxh = a.at(j);
			}
		}
		if (cntcolor==k){
			ans = min(ans, cnt);
		}
	}
	cout << ans << endl;
}