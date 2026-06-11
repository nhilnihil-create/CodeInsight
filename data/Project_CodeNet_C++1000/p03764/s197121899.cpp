#include <bits/stdc++.h>
typedef long long ll;
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
#define REP(i,a) FOR(i,0,a)
	
using namespace std;
const int MAX_N=1e5,MAX_M=1e5;
const ll MOD=1e9+7;
ll n,m;
ll x[MAX_N],y[MAX_M];
int main(){
	cin>>n>>m;
	REP(i,n){
		cin>>x[i];
	}
	REP(i,m){
		cin>>y[i];
	}
	ll xsm=0,ysm=0;
	REP(i,n-1){
		xsm+=(i+1)*(n-i-1)%MOD*(x[i+1]-x[i])%MOD;
		xsm%=MOD;
	}
	REP(i,m-1){
		ysm+=(i+1)*(m-i-1)%MOD*(y[i+1]-y[i])%MOD;
		ysm%=MOD;
	}
	cout<<xsm*ysm%MOD<<endl;
	return 0;
}