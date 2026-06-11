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

	lli n;
	cin>>n;

	vector<lli> a(n),b(n);
	REP(i,0,n){
		a[i] = 40000*(i+1);
		b[i] = 40000*(n-i);
	}

	lli cnt = 0;
	REP(i,0,n){
		lli p;
		cin>>p;
		p--;
		b[p] += i;
	}

	REP(i,0,n)cout<<a[i]<<" ";
	cout<<endl;
	REP(i,0,n)cout<<b[i]<<" ";
	cout<<endl;


	return 0;
}