#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX_N 100005
const ll INF = (1LL<<60);

ll max(ll a,ll b,ll c){
  return max(a,max(b,c));
}

int N;
ll A[MAX_N];
ll dp[MAX_N][3];

int main(){
  for(int i=0;i<MAX_N;i++)
    for(int j=0;j<3;j++)
      dp[i][j]=-INF;
  cin>>N;
  cin>>dp[0][0];
  
  for(int i=0;i<N-1;i++){
    char ch;
    ll x;
    cin>>ch>>x;

    if(ch=='+'){
      dp[i+1][0]=max(dp[i][0]+x,dp[i][1]+x);
      dp[i+1][1]=max(dp[i][1]-x,dp[i][2]-x);
      dp[i+1][2]=dp[i][2]+x;
    }else if(ch=='-'){
      dp[i+1][0]=-INF;
      dp[i+1][1]=max(dp[i][0]-x,dp[i][1]-x,dp[i][2]-x);
      dp[i+1][2]=max(dp[i][1]+x,dp[i][2]+x);
    }

  }
  cout<< max(dp[N-1][0], max(dp[N-1][1],dp[N-1][2])) <<endl;
  return 0;
}
