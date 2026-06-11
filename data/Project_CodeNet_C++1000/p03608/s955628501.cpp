#include <bits/stdc++.h>
 
using namespace std;
 
#define lli long long int
#define lld long double
#define REP(i,s,n) for(lli i=s;i<n;i++)
#define RREP(i,s,n) for(lli i=s;i>=n;i--)
#define MOD 1000000007
#define NUM 2520
#define DEBUG 1
#define mp(a,b) make_pair(a,b)
#define SORT(V) sort(V.begin(),V.end())
#define PI (3.141592653589794)
#define INF (1LL<<50)

signed main(){

	lli d[300][300];
	REP(i,0,300)REP(j,0,300)d[i][j]=INF;

	lli N,M,R;
	cin>>N>>M>>R;
	vector<lli> r(R);
	REP(i,0,R){
		cin>>r[i];
		r[i]--;
	}

	REP(i,0,M){
		lli a,b,c;
		cin>>a>>b>>c;
		a--,b--;
		d[a][b] = min(d[a][b],c);
		d[b][a] = min(d[b][a],c);
	}

	REP(k,0,N)REP(i,0,N)REP(j,0,N)d[i][j] = min(d[i][j],d[i][k]+d[k][j]);

	vector<lli> per(R);
	REP(i,0,R)per[i]=i;

	lli ans = INF;
	do{
		lli nowPos = r[per[0]];
		lli sum= 0;
		REP(i,1,R){
			sum += d[nowPos][r[per[i]]];
			nowPos = r[per[i]];
		}
		ans = min(ans,sum);
	}while(next_permutation(per.begin(),per.end()));

	cout<<ans<<endl;

	return 0;
}