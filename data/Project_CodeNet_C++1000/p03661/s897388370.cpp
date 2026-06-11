#include <bits/stdc++.h>
typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,a) FOR(i,0,a)
	
using namespace std;
const int MAX_N=2e5;
const ll INF=1e18;
int N;
ll psm[MAX_N+1];
int main(){
	cin>>N;
	psm[0]=0;
	REP(i,N){
		ll a;
		cin>>a;
		psm[i+1]=psm[i]+a;
	}
	ll ans=INF;
	REP(i,N-1){
		ans=min(ans,llabs(psm[i+1]-(psm[N]-psm[i+1])));
	}
	cout<<ans<<endl;
	return 0;
}