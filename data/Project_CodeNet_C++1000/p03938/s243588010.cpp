#include <bits/stdc++.h>
 
using namespace std;
 
#define lli long long int
#define REP(i,s,l) for(lli i=s;i<l;i++)
#define DEBUG 0
#define INF (1LL<<50)
#define MOD 1000000007

signed main(){

	lli n;
	cin>>n;

	vector<lli> p(n);
	REP(i,0,n){
		cin>>p[i];
		p[i]--;
	}

	lli m = 40000;
	vector<lli> a(n),b(n);
	REP(i,0,n){
		a[i] = m*(i+1);
		b[i] = m*(n-i);
	}

	for(lli i=0;i<n;i++){
		lli index = p[i];
		a[index]+=(i+1);
	}

	REP(i,0,n)cout<<a[i]<<" ";
	cout<<endl;
	REP(i,0,n)cout<<b[i]<<" ";
	cout<<endl;

	return 0;
}