#include <bits/stdc++.h>

using namespace std;

#define lli long long int
#define REP(i,s,n) for(int i=s;i<n;i++)
#define MOD 1000000007
#define NUM 2520
#define INF (1LL<<60)
#define DEBUG 0
#define mp(a,b) make_pair(a,b)
#define SORT(V) sort(V.begin(),V.end())
#define PI (3.141592653589794)

lli bitCnt(lli now){
	lli cnt=0;
	while(now>0){
		cnt += (now%2);
		now/=2;
	}
	return cnt;
}

signed main(){

	lli n,k;
	cin>>n>>k;

	vector<lli> a(n);
	REP(i,0,n)cin>>a[i];

	vector<lli> amaxh(n+1);
	amaxh[0]=0;
	REP(i,0,n)amaxh[i+1] = max(a[i],amaxh[i]);
	lli ans = INF;

	for(lli b=0;b<(1LL<<(n));b++){
		if(__builtin_popcount(b) != k) continue;
		if(DEBUG)cout<<"b="<<b<<endl;
		lli nowh=0,tmp=0;
		REP(i,0,n){
			if(DEBUG)cout<<"i="<<i<<endl;
			if((b&(1LL<<i))==0)continue;
			nowh=max(nowh,amaxh[i]);
			if(nowh>=a[i]){
				tmp += nowh-a[i]+1;
				nowh++;
			}
			else{
				nowh = a[i];
			}
		}
		ans = min(ans,tmp);
	}
	cout<<ans<<endl;


	return 0;
}