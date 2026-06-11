#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,n) for(int i=(int)(j);i<(int)(n);i++)
#define REP(i,j,n) for(int i=(int)(j);i<=(int)(n);i++)
#define MOD 1000000007
#define int long long
#define ALL(a) (a).begin(),(a).end()
#define vi vector<int>
#define vii vector<vi>
#define pii pair<int,int>
#define priq priority_queue<int>
#define disup(A,key) distance(A.begin(),upper_bound(ALL(A),(int)(key)))
#define dislow(A,key) distance(A.begin(),lower_bound(ALL(A),(int)(key)))
#define tii tuple<int,int,int>
#define Priq priority_queue<int,vi,greater<int>>
#define pb push_back
#define mp make_pair
#define INF (1ll<<60)
signed main(){
  int N,P,Q; cin>>N>>P>>Q;
  vector<vii> dp(N+1,vii(10*N+1,vi(10*N+1,INF)));
  dp[0][0][0]=0;
  rep(i,0,N){
    int A,B,C; cin>>A>>B>>C;
    REP(j,0,N*10){
      REP(k,0,N*10){
        if(dp[i][j][k]!=INF){
          dp[i+1][j][k]=min(dp[i][j][k],dp[i+1][j][k]);
          dp[i+1][j+A][k+B]=min(dp[i+1][j+A][k+B],dp[i][j][k]+C);
        }
      }
    }
  }
  int ans=INF;
  REP(i,1,min(10*N/P,10*N/Q)){
    if(dp[N][i*P][i*Q]!=INF) ans=min(ans,dp[N][i*P][i*Q]);
  }
  if(ans==INF) ans=-1;
  cout<<ans<<endl;
  }

