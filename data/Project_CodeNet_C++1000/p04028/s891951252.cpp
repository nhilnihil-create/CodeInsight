#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) x.begin(),x.end()
#define dmp(x) cerr<<#x<<":"<<x<<endl
#define FOR(i,a,b) for(int i=(int)a,c=(int)b;i<c;++i)
#define rep(i,b) FOR(i,0,b)
#define ROF(i,a,b) for(int i=b-1,c=(int)a;i>=c;--i)
#define per(i,b) ROF(i,0,b)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
int dp[5010][5010];

signed main(){
  int n,mod=1000000007;
  string s;
  cin>>n>>s;
  int m=s.size();
  dp[0][0]=1;
  rep(i,n){
    rep(j,5001){
	 dp[i+1][j+1]+=dp[i][j];
	 dp[i+1][j+1]%=mod;
	 if(j>0){
	   dp[i+1][j-1]+=dp[i][j]*2;
	   dp[i+1][j-1]%=mod;
	 }else{
	   dp[i+1][j]+=dp[i][j];
	   dp[i+1][j]%=mod;
	 }
    }
  }
  cout<<dp[n][m]<<endl;
  return 0;
}
