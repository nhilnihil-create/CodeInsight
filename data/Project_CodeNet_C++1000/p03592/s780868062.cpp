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

	lli n,m,k;
	cin>>n>>m>>k;

	for(lli a=0;a<=n;a++){
		for(lli b=0;b<=m;b++){
			if( (m-b)*a + (n-a)*b == k){
				cout<<"Yes"<<endl;
				return 0;
			}
		}
	}

	cout<<"No"<<endl;

	return 0;
}