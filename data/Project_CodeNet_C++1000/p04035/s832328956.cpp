#include <bits/stdc++.h>
 
using namespace std;
 
#define lli long long int
#define lld long double
#define REP(i,s,n) for(lli i=s;i<n;i++)
#define RREP(i,s,n) for(lli i=s;i>=n;i--)
#define MOD 1000000007
#define NUM 2520
#define DEBUG 0
#define mp(a,b) make_pair(a,b)
#define SORT(V) sort(V.begin(),V.end())
#define PI (3.141592653589794)
#define INF (1LL<<50)

signed main(){

	lli n,l;
	cin>>n>>l;

	vector<lli> a(n);
	REP(i,0,n)cin>>a[i];

	REP(i,0,n-1){
		if(a[i]+a[i+1]>=l){
			cout<<"Possible"<<endl;
			lli target = i+1;
			REP(j,1,target){
				cout<<j<<endl;
			}

			for(lli j=n-1;j>i;j--){
				cout<<j<<endl;
			}
			return 0;
		}
	}

	cout<<"Impossible"<<endl;

	return 0;
}