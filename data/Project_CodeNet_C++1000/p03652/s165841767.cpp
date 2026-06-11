#include <bits/stdc++.h>

using namespace std;

#define lli long long int
#define REP(i,s,n) for(int i=s;i<n;i++)
#define MOD 1000000007
#define NUM 2520
#define INF (1LL<<50)
#define DEBUG 0
#define mp(a,b) make_pair(a,b)
#define SORT(V) sort(V.begin(),V.end())

lli data[400][400];

signed main(){

	set<lli> s;
	lli n,m;
	cin>>n>>m;
	lli flag[400];

	for(lli i=1;i<=m;i++)flag[i]=1;

	REP(i,0,n)REP(j,0,m)cin>>data[i][j];

	lli ans = INF;
	lli ansIndex=-1;
	while(true){
		lli b=0;
		for(lli i=1;i<=m;i++){
			if(flag[i]==1)b=1;
		}
		if(b==0)break;
		lli dp[400];
		REP(i,0,400)dp[i]=0;

		REP(i,0,n){
			if(DEBUG)cout<<"i="<<i<<endl;
			REP(j,0,m){
				lli nowS = data[i][j];
				if(flag[nowS]){
					if(DEBUG)cout<<"nowS=="<<nowS<<endl;
					dp[nowS]++;
					break;
				}
			}
		}
		lli nowMax=0;

		REP(i,0,400){
			if(dp[i]==0)continue;
			if(DEBUG)cout<<"i="<<i<<" dp[i]="<<dp[i]<<endl;
			if(nowMax<=dp[i]){
				nowMax = dp[i];
				ansIndex = i;
			}
		}
		ans = min(ans,nowMax);
		if(DEBUG)cout<<"ansINdex="<<ansIndex<<endl;
		flag[ansIndex]=0;
	}

	cout<<ans<<endl;

	return 0;
}