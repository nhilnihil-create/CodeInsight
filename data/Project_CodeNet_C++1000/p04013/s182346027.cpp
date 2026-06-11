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

signed main(){
	ll n,m; cin>>n>>m;
	vl vec(n+1);
	rep(i,0,n){
		cin>>vec[i];
		vec[i]-=m;
	}
	vvl dp(55,vl(20100));
	dp[0][10000]=1;
	rep(i,0,n){
		rep(j,-10000,10000){
			ll k=j+10000;
			dp[i+1][k]=dp[i][k];
			if(k-vec[i]>=0 && k-vec[i]<20100)dp[i+1][k]+=dp[i][k-vec[i]];
		}
	}
	cout<<dp[n][10000]-1<<endl;
	return 0;
}