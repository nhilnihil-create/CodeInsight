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
  int N,M; cin>>N>>M;
  vii A(N,vi(N,INF));
  rep(i,0,M){
    int X,Y,Z; cin>>X>>Y>>Z;
    A[X-1][Y-1]=Z;
    A[Y-1][X-1]=Z;
  }
  vector<vector<bool>> F(N,vector<bool>(N));
  rep(i,0,N){
    vi memo(N);
    memo[i]=-1;
    priority_queue<pii,vector<pii>,greater<pii>> Q;
    Q.push(mp(0,i));
    vi B(N,MOD);
    B[i]=0;
    while(Q.size()>0){
      int X=Q.top().second,Y=Q.top().first;
      Q.pop();
      rep(j,0,N){
        if(B[j]>Y+A[X][j]){
          B[j]=Y+A[X][j];
          Q.push(mp(Y+A[X][j],j));
          memo[j]=X;
        }
      }
    }
    rep(i,0,N){
      int P=i;
      while(memo[P]!=-1){
        F[P][memo[P]]=1;
        P=memo[P];
      }
    }
  }
  int ans=0;
  rep(i,0,N){
    rep(j,0,N){
      if(F[i][j])
        ans++;
    }
  }
  cout<<M-ans/2<<endl;
  }
