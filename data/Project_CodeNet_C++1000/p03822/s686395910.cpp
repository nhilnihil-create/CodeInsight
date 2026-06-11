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
  int N; cin>>N;
  vii A(N);
  vi B(N);
  rep(i,1,N){
    int X; cin>>X;
    A[i].pb(X-1);
    B[X-1]++;
  }
  stack<int> S;
  rep(i,0,N){
    if(B[i]==0) S.push(i);
  }
  vi C;
  while(S.size()>0){
    int X=S.top(); S.pop();
    C.pb(X);
    rep(i,0,A[X].size()){
      int Y=A[X][i];
      B[Y]--;
      if(B[Y]==0) S.push(Y);
    }
  }
  vii D(N);
  vi dp(N);
  rep(i,0,N){
    sort(ALL(D[C[i]]));
    int X=D[C[i]].size();
    rep(j,0,X){
      dp[C[i]]=max(dp[C[i]],D[C[i]][j]+X-j);
    }
    rep(j,0,A[C[i]].size()){
      D[A[C[i]][j]].pb(dp[C[i]]);
    }
  }
  int ans=0;
  rep(i,0,N) ans=max(ans,dp[i]);
  cout<<ans<<endl;
  }


