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
signed main(){
  int N,A; cin>>N>>A;
  vector<map<int,int>> dp(N+1);
  dp[0][0]=1;
  REP(i,1,N){
    int X; cin>>X;
    int Y=X-A;
    for(auto p:dp[i-1]){
      int P=p.first,Q=p.second;
      dp[i][P]+=Q;
      dp[i][P+Y]+=Q;
    }
  }
  cout<<dp[N][0]-1<<endl;
  }
