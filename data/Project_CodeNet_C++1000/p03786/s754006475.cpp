#include <bits/stdc++.h>
#define REP(i,n)   for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(long long i=(a);((a)<(b)?i<=(b):i>=(b));((a)<(b)?++i:--i))
#define ALL(v)     (v).begin(),(v).end()
#define debug(x)   cerr<<#x<<": "<<(x)<<endl
using namespace std;
typedef long long     llong;
typedef vector<int>   vi;
typedef vector<vi >   vvi;
typedef vector<vvi >  vvvi;
typedef pair<int,int> pii;
constexpr int    INF=1e9;
constexpr double EPS=1e-9;
constexpr int    MOD=1e9+7;
template<class Type>
void line(const Type &a){int cnt=0;for(const auto &elem:a){cerr<<(cnt++?' ':'>');cerr<<elem;}cerr<<endl;}

int main(){
	int n;
	cin>>n;
	
	vector<llong> a(n);
	REP(i,n) cin>>a[i];
	sort(ALL(a));
	
	int ans=1;
	llong sum=0;
	REP(i,n-1){
		sum+=a[i];
		if(a[i+1]<=2*sum) ans++;
		else ans=1;
	}
	
	cout<<ans<<endl;
}