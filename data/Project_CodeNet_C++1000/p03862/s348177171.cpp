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
//priority_queue<ll, vector<ll>, greater<ll>> q;
using pl = pair<ll,ll>;
signed main(){
	ll n,x; cin>>n>>x;
	vl a(n);
	rep(i,0,n)cin>>a[i];
	vl b=a;
	rep(i,1,n){
		if(a[i]+a[i-1]<=x)continue;
		ll k=(a[i]+a[i-1])-x;
		if(a[i]<k){
			k-=a[i];
			a[i]=0;
			a[i-1]-=k;
		}
		else{
			a[i]-=k;
		}
	}
	ll ans=0;
	rep(i,0,n)ans+=b[i]-a[i];
	cout<<ans<<endl;
	return 0;
}