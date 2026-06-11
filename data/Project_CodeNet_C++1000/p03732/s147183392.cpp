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
  int N,W; cin>>N>>W;
  int ans=0;
  vii A(4);
  int memo=0; cin>>memo;
  int X; cin>>X;
  A[0].push_back(X);
  rep(i,0,N-1){
    int X,Y; cin>>X>>Y;
    A[X-memo].push_back(Y);
  }
  vii S(4);
  rep(i,0,4){
    sort(ALL(A[i]),greater<int>());
    int sum=0;
    S[i].push_back(0);
    rep(j,0,A[i].size()){
      sum+=A[i][j];
      S[i].push_back(sum);
    }
  }
  REP(i,0,A[0].size()){
    REP(j,0,A[1].size()){
      REP(k,0,A[2].size()){
        REP(l,0,A[3].size()){
          int K=i*memo;
          K+=j*memo+j;
          K+=k*memo+k*2;
          K+=l*memo+l*3;
          if(K<=W){
            int sum=0;
            sum+=S[0][i];
            sum+=S[1][j];
            sum+=S[2][k];
            sum+=S[3][l];
            ans=max(ans,sum);
          }
        }
      }
    }
  }
  cout<<ans<<endl;
  }

