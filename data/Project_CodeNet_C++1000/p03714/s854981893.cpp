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
#define inf (1ll<<60)
signed main(){
  int N; cin>>N;
  Priq Q;
  vi A(3*N);
  rep(i,0,3*N) cin>>A[i];
  vi B(N+1);
  rep(i,0,N){
    B[0]+=A[i];
    Q.push(A[i]);
  }
  rep(i,N,2*N){
    int K=i-N+1;
    B[K]=B[K-1]+A[i];
    Q.push(A[i]);
    B[K]-=Q.top();
    Q.pop();
  }
  vi C(N+1);
  priq P;
  REP(i,1,N){
    int K=3*N-i;
    C[0]+=A[K];
    P.push(A[K]);
  }
  REP(i,1,N){
    int K=2*N-i;
    C[i]=C[i-1]+A[K];
    P.push(A[K]);
    C[i]-=P.top();
    P.pop();
  }
  int ans=-inf;
  REP(i,0,N){
    ans=max(B[i]-C[N-i],ans);
  }
  cout<<ans<<endl;
  }
