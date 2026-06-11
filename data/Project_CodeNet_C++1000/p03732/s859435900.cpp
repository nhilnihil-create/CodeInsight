#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)



int main(){
  ll N,W;
  cin >> N >>W;
  ll w[N],v[N];
  cin >> w[0] >> v[0];
  ll offset=w[0];
  w[0]=0;
  ll t;
  rep1(i,N-1){
    cin >> t >> v[i];
    w[i] = t-offset;    
  }
  //  rep(i,N) cout << w[i] << endl;
  ll dp[4*N+1][N+1][N+1]; //(offsetを除いた)重さi以下の制限の元jこまでのうちkこ使った場合の価値の総和の最大値
  rep(i,4*N+1)rep(j,N+1) rep(k,N+1) dp[i][j][k]=0;
  rep1(j,N){
    rep1(k,j){
      rep(i,4*N+1){
	if(j==k){
	  if(i-w[j-1]>=0){
	    dp[i][j][k]= max(dp[i-w[j-1]][j-1][k-1] + v[j-1] , dp[i][j-1][k-1]);
	  }else{
	    dp[i][j][k] = dp[i][j-1][k];	    
	  }	  
	}
	else if(i-w[j-1]>=0){	  
	  dp[i][j][k] = max(dp[i-w[j-1]][j-1][k-1] + v[j-1] , dp[i][j-1][k]);
	}else{
	  dp[i][j][k] = dp[i][j-1][k];
	}
      }
    }
  }
  ll ans=0;
  //  cout << offset << endl;
  rep(i,4*N+1)rep(k,N+1){
    //    if(k==1)cout <<"w " << k*offset+i << " v "<< dp[i][N][k] << endl;
    if(k*offset+i<=W){
      ans=max(ans,dp[i][N][k]);
    }
  }
  cout << ans << endl;


  
  return 0;

}
