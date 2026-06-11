#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
#define ALL(v)   (v).begin(),(v).end()
#define debug(x) cerr<<#x<<": "<<(x)<<endl
#define INF      (int)1e9
#define EPS      (double)1e-9
#define MOD      ((int)1e9+7)
using namespace std;
typedef long long     llong;
typedef vector<int>   vi;
typedef vector<vi >   vvi;
typedef vector<vvi >  vvvi;
typedef pair<int,int> pii;
template<class Type> void line(const Type &a){int cnt=0;for(const auto &elem:a){if(cnt++)cout<<' ';cout<<elem;}cout<<endl;}

//解説参考.
int main(){
	llong x,y;
	cin>>x>>y;
	
	llong ans=1e18;
	REP(i,2)REP(j,2){
		llong cnt=0;
		llong xx=x, yy=y;
		if(i){
			xx=-x;
			cnt++;
		}
		if(j){
			yy=-y;
			cnt++;
		}
		if(xx<=yy){
			cnt+=yy-xx;
			ans=min(ans,cnt);
		}
	}
	
	cout<<ans<<endl;
}