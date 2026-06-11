#include <bits/stdc++.h>
typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,a) FOR(i,0,a)
	
using namespace std;
const int MAX_N=1e6;
const ll MOD=1e9+7;
ll n;
ll dp[MAX_N+1];
int main(){
	cin>>n;
	dp[0]=1;
	dp[1]=n;
	dp[2]=n*n%MOD;
	ll sm=(1+n+n*n)%MOD;
	FOR(i,3,n+1){
		ll v=(sm-dp[i-2]+MOD)%MOD;
		v+=n-i+1;
		v%=MOD;
		v+=(n-1)*(n-1)%MOD;
		v%=MOD;
		dp[i]=v;
		sm+=v;
		sm%=MOD;
	}
	cout<<dp[n]<<endl;
	return 0;
}