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
  vi A(N);
  rep(i,0,N) cin>>A[i];
  sort(ALL(A));
  if(A[N-1]-A[0]==0){
    int X=A[0];
    if(X+1==N||N>=X*2) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
  }
  else if(A[N-1]-A[0]==1){
    int P=A[0],Q=A[N-1],R=0,S=0;
    rep(i,0,N){
      if(A[i]==P) R++;
      else S++;
    }
    if(P==R) cout<<"Yes"<<endl;
    else if(P>=R&&(Q-R)*2<=S) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
  }
  else cout<<"No"<<endl;
  }


