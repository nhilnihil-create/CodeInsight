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
  vi A;
  A.pb(K);
  bitset<60> b(K);
  rep(i,1,60){
    if(b.test(i)){
      int X=K|((1ll<<i)-1);
      X-=(1ll<<i);
      A.pb(X);
    }
  }
  int M=A.size();
  vi B(M);
  rep(i,0,N){
    int X,Y; cin>>X>>Y;
    rep(j,0,M){
      if((A[j]|X)==A[j]) B[j]+=Y;
    }
  }
  int ans=0;
  rep(i,0,M) ans=max(ans,B[i]);
  cout<<ans<<endl;
  }
