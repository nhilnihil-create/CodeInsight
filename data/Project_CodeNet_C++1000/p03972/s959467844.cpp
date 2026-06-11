#include <bits/stdc++.h>

using namespace std;

#define lli long long int
#define REP(i,s,n) for(int i=s;i<n;i++)
#define MOD 1000000007
#define NUM 2520
#define INF (1LL<<50)
#define DEBUG 0
#define mp(a,b) make_pair(a,b)

int main(){

	lli w,h;
	cin>>w>>h;

	vector<lli> p(w),q(h);

	REP(i,0,w)cin>>p[i];
	REP(i,0,h)cin>>q[i];

	sort(p.begin(),p.end());
	sort(q.begin(),q.end());

	lli pi=0,qi=0;

	lli ans=0;
	while(true){
		if(pi == p.size()){
			for(;qi<q.size();qi++)ans+=q[qi];
			break;
		}
		if(qi == q.size()){
			for(;pi<p.size();pi++)ans+=p[pi];
			break;
		}

		if(p[pi]<=q[qi]){
			ans += p[pi]*(h+1-qi);
			pi++;
		}
		else{
			ans += q[qi]*(w+1-pi);
			qi++;
		}
	}
	cout<<ans<<endl;

	return 0;
}