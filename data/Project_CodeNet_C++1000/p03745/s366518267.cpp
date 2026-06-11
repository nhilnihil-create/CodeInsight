#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
#define all(x) x.begin(),x.end()
#define rep(i,j,n) for (long long i = j; i < (long long)(n); i++)
#define _GLIBCXX_DEBUG
#define MOD 1000000007
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//(a+b-1)/b

signed main(){
	int n; cin>>n;
	vl a(n);
	rep(i,0,n)cin>>a[i];
	ll ans=1;
	ll now;
	ll tmp;
	rep(i,1,n){
		if(a[i-1]<a[i])now=1;
		else if(a[i-1]>a[i])now=-1;
		else now=0;
		if(i==1 || tmp==0)tmp=now;
		if(now==0)continue;
		if(now!=tmp){
			ans++;
			tmp=0;
		}

	}
	cout<<ans<<endl;

	
	return 0;
}