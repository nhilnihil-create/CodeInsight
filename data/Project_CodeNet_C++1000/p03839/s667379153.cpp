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
  vi cp(N+1),dp(N+1),bp(N+1),ap(N+1);
  rep(i,0,N) bp[i+1]=max(0ll,A[i])+bp[i];
  REP(i,1,N) cp[N-i]=max(0ll,A[N-i])+cp[N-i+1];
  rep(i,0,N) ap[i+1]=ap[i]+A[i];
  int ans=0;
  REP(i,K,N){
    int X=max(0ll,ap[i]-ap[i-K]);
    ans=max(ans,X+bp[i-K]+cp[i]);
  }
  cout<<ans<<endl;
  }

