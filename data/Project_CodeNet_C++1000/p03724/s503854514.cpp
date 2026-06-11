#include <bits/stdc++.h>
 
using namespace std;
 
#define lli long long int
#define REP(i,s,n) for(int i=s;i<n;i++)
#define MOD 1000000007
#define NUM 2520
#define DEBUG 0
#define mp(a,b) make_pair(a,b)
#define SORT(V) sort(V.begin(),V.end())
#define PI (3.141592653589794)
#define INF (1LL<<50)
 
map<lli,lli> cnt;

signed main(){

	lli n;
	cin>>n;
	lli m;
	cin>>m;

	REP(i,0,m){
		lli a,b;
		cin>>a>>b;
		cnt[a]++;
		cnt[b]++;
	}

	for(auto e:cnt){
		if(e.second%2){
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;


	return 0;
}