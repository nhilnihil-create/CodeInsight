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
#define PI (3.141592653589794)
 
signed main(){
 
	lli n;
	cin>>n;

	vector<lli> a(n);
	REP(i,0,n)cin>>a[i];

	lli ans=(a[0]-1);
	lli now=2;
	REP(i,1,n){
		//if(now>=a[i])continue;
		if(DEBUG)cout<<"i="<<i<<"ans[i]="<<ans<<"now="<<now<<endl;
		if(now>a[i])continue;
		if(now==a[i]){
			now = a[i]+1;
			continue;
		}
		if(a[i]%now==0){
			a[i] -= (now+1);
			ans ++ ;
		}
		ans += (a[i]-1)/now;
	}
	cout<<ans<<endl;

	return 0;
 
}