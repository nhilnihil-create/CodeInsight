#include<bits/stdc++.h>
#define INF (1e15)
#define int long long
using namespace std;

int n, dp[100005][3];
char C[100005];
int A[100005];

void solve(){
  
  for(int i=0;i<=n;i++)
    for(int j=0;j<3;j++) dp[i][j]=-INF;
  
  dp[1][0]=A[0];
  
  for(int i=1;i<n;i++){
    
    for(int j=0;j<3;j++){
      
      if(dp[i][j]==-INF) continue;
      
      char c=C[i];
      int num=A[i];  
      
      if(c=='+'){
	
	if(j==0) dp[i+1][0]=max(dp[i+1][0], dp[i][j]+num);
	
	if(j==1){
	  dp[i+1][0]=max(dp[i+1][0], dp[i][j]+num);
	  dp[i+1][1]=max(dp[i+1][1], dp[i][j]-num);
	}
	if(j==2){
	  dp[i+1][1]=max(dp[i+1][1], dp[i][j]-num);
	  dp[i+1][2]=max(dp[i+1][2], dp[i][j]+num);
	}
	    
      } else{
	
	if(j==0){
	  dp[i+1][0]=max(dp[i+1][0], dp[i][j]-num);
	  dp[i+1][1]=max(dp[i+1][1], dp[i][j]-num);
	}
	if(j==1){
	  dp[i+1][0]=max(dp[i+1][0], dp[i][j]-num);
	  dp[i+1][1]=max(dp[i+1][1], dp[i][j]+num);
	  dp[i+1][2]=max(dp[i+1][2], dp[i][j]+num);
	}
	if(j==2){
	  dp[i+1][1]=max(dp[i+1][1], dp[i][j]-num);
	  dp[i+1][2]=max(dp[i+1][2], dp[i][j]+num);
	}
		
      }
      
    }
  }
  
  int ans=-INF;
  
  for(int i=0;i<3;i++) ans=max(ans, dp[n][i]);
  
  cout<<ans<<endl;
}

signed main(){
  
  cin>>n;
  
  cin>>A[0];
  
  for(int i=1;i<n;i++) cin>>C[i]>>A[i];
  
  solve();
  
  return 0;
}
