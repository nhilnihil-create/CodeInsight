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
  int N,K; cin>>N>>K;
  vi A(N);
  rep(i,0,N) cin>>A[i];
  vector<vector<bool>> dp(N+1,vector<bool>(K+1)),cp(N+1,vector<bool>(K+1));
  dp[0][0]=1;
  rep(i,0,N){
    REP(j,0,K){
      if(dp[i][j]){
        dp[i+1][j]=1;
        dp[i+1][min(j+A[i],K)]=1;
      }
    }
  }
  cp[N][0]=1;
  rep(i,0,N){
    int k=N-i;
    REP(j,0,K){
      if(cp[k][j]){
        cp[k-1][j]=1;
        cp[k-1][min(j+A[k-1],K)]=1;
      }
    }
  }
  int ans=0;
  rep(i,0,N){
    int sum=0;
    int memo=K-1;
    rep(j,0,K){
      if(dp[i][j]){
        for(memo;0<=memo;memo--){
          if(cp[i+1][memo]&&memo+j<K){
            sum=max(sum,memo+j);
            break;
          }
        }
      }
    }
    if(sum+A[i]<K) ans++;
  }
  cout<<ans<<endl;
  }

