#include<bits/stdc++.h>
using namespace std;
using Int = long long;

template<typename T> void chmin(T &a,T b){if(a>b) a=b;}
template<typename T> void chmax(T &a,T b){if(a<b) a=b;}

const Int MAX = 214514;
const Int INF = 1145141919810893;
Int dp[2][2][MAX];
signed main(){
  Int n;
  cin>>n;
  vector<Int> a(n);
  vector<char> b(n-1);
  for(Int i=0;i<n*2-1;i++){
    if(i&1) cin>>b[i/2];
    else cin>>a[i/2];
  }
  for(Int i=0;i<2;i++)
    for(Int j=0;j<2;j++)
      for(Int k=0;k<MAX;k++)
	dp[i][j][k]=-INF;
  
  Int sgn[]={1,-1};
  dp[0][1][0]=0;
  for(Int i=0;i<2*n-1;i++){
    Int x=i>>1;
    if(i&1){
      if(b[x]=='+'){
	for(Int j=0;j<2;j++)
	  for(Int k=0;k<2;k++)
	    chmax(dp[j][k][i+1],dp[j][k][i]);
      }else{
	for(Int j=0;j<2;j++)
	  for(Int k=0;k<2;k++)
	    chmax(dp[!j][0][i+1],dp[j][k][i]);	
      }
    }else{
      for(Int j=0;j<2;j++){
	chmax(dp[j][0][i+1],dp[j][0][i]+sgn[j]*a[x]);
	chmax(dp[!j][1][i+1],dp[j][0][i]+sgn[j]*a[x]);
	chmax(dp[j][1][i+1],dp[j][1][i]+sgn[j]*a[x]);
      } 
    }
  }

  Int ans=-INF;
  for(Int i=0;i<2;i++)
    for(Int j=0;j<2;j++)
      chmax(ans,dp[i][j][2*n-1]);
  cout<<ans<<endl;
  return 0;
}
