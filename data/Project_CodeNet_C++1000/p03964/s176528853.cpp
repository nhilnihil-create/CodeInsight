#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
#define all(x) x.begin(),x.end()
#define rep(i,j,n) for (int i = j; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define MOD 1000000007
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//a/bの天井関数 =>  (a + b - 1) / b 

signed main(){
	int n; cin>>n;
	pair<ll,ll> ans;
	cin>>ans.first>>ans.second;
	rep(i,0,n-1){
		ll x=ans.first;
		ll y=ans.second;
		ll a,b; cin>>a>>b;
		ll s =  (x + a - 1) / a; 
		ll t =  (y + b - 1) / b;
		ll m=max(s,t);
		ans=pair<ll,ll>(a*m,b*m);
	}
	
	cout<<ans.first+ans.second;
	
	return 0;
}