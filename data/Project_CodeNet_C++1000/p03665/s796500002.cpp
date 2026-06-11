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
	ll n,p; cin >> n >> p;
	vl vec(n); rep(i,0,n) cin >> vec[i];
	vvl dp(55,vl(10000));
	dp[0][0]=1;
	rep(i,0,n){
		rep(j,0,10000){
			dp[i+1][j]=dp[i][j];
			if(j-vec[i]>=0)dp[i+1][j]+=dp[i][j-vec[i]];
		}
	}
	ll ans=0;
	rep(i,0,10000){
		if(i%2==p){
			ans+=dp[n][i];
		}
	}
	cout<<ans<<endl;
	return 0;
}