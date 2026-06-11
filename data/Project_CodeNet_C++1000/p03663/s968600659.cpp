#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef pair<long long, long long> l4;
typedef vector<long long> vll;
typedef double db;
typedef vector<double> vdb;
typedef pair<double, double> dd;
typedef set<int> si;
typedef set<long long> sll;
#define fi first
#define se second
#define matrix(a) vector< vector<a> >
#define sz(a) int((a).size()) 
#define lop(i,a,b) for (int i=a; i<=b; i++)
#define vlop(i,v) lop(i,0,sz(v)-1)
#define vlop1(i,v) lop(i,1,sz(v)-1)
#define rlop(i,a,b) for (int i=b; i>=a; i--)
#define vrlop(i,v) rlop(i,0,sz(v)-1)
#define vrlop1(i,v) rlop(i,1,sz(v)-1)
#define printv(i,v) vlop(i,v)cout<<v[i]<<" "
#define printv1(i,v) vlop1(i,v)cout<<v[i]<<" "
#define all(s) (s).begin(),(s).end()
#define pb push_back
#define enter cout<<'\n'
#define lb(i,v) int(lower_bound(all(v),i)-v.begin())
#define ub(i,v) int(upper_bound(all(v),i)-v.begin())

int main() {
	ll n=1;
	string ans;
	while(n<=1e9){
		cout<<"? "<<n<<'\n';
		fflush(stdout);
		cin>>ans;
		if(ans[0]=='N')break;
		n*=10;
	}
	if(n==1e10){
		n=1;
		while(n<=1e9){
		cout<<"? "<<n+1<<'\n';
		fflush(stdout);
		cin>>ans;
		if(ans[0]=='Y')break;
		n*=10;
	}
	cout<<"! "<<n;
	}
	else{
	    ll l=n/10+1,u=n-1,med;
	    while(l<u){
	    	med=(l+u)/2;
	    	cout<<"? "<<med*10<<'\n';
	    	fflush(stdout);
	    	cin>>ans;
	    	if(ans[0]=='Y')u=med;
	    	else l=med+1;
	    }
	    cout<<"! "<<l;
	}
	return 0;
}