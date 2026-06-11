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
  vector<vector<pii>> A(N);
  vii C(N);
  rep(i,0,M){
    int X,Y,Z; cin>>X>>Y>>Z;
    A[X-1].pb(mp(Y-1,Z));
    C[Y-1].pb(X-1);
  }
  priority_queue<pii> Q;
  Q.push(mp(0,0));
  vi B(N);
  vector<bool> F(N);
  F[N-1]=1;
  queue<int> q;
  q.push(N-1);
  while(q.size()>0){
    int X=q.front();
    q.pop();
    rep(i,0,C[X].size()){
      int Y=C[X][i];
      if(!F[Y]){
        F[Y]=1;
        q.push(Y);
      }
    }
  }
  vi G(N,-INF);
  G[0]=0;
  while(Q.size()>0){
    int X=Q.top().second,Y=Q.top().first; Q.pop();
    if(G[X]>Y) continue;
    if(B[X]>N){
      cout<<"inf"<<endl;
      return 0;
    }
    rep(i,0,A[X].size()){
      int P=A[X][i].first,R=A[X][i].second+Y;
      if(F[P]&&G[P]<R){
        G[P]=R;
        Q.push(mp(R,P));
        B[P]++;
      }
    }
  }
  cout<<G[N-1]<<endl;
  }

