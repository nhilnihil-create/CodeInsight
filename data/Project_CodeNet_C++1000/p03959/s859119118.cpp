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
  vi A(N),B(N);
  rep(i,0,N) cin>>A[i];
  rep(i,0,N) cin>>B[i];
  vi C(N),D(N);
  C[0]=A[0];
  D[0]=A[0];
  rep(i,1,N){
    if(A[i-1]<A[i]){
      C[i]=A[i];
      D[i]=A[i];
    }
    else{
      D[i]=A[i];
      C[i]=1;
    }
  }
  vi E(N),F(N);
  E[N-1]=B[N-1];
  F[N-1]=B[N-1];
  REP(i,2,N){
    int j=N-i;
    if(B[j]>B[j+1]){
      E[j]=B[j];
      F[j]=B[j];
    }
    else{
      F[j]=B[j];
      E[j]=1;
    }
  }
  int ans=1;
  rep(i,0,N){
    if(D[i]<E[i]||F[i]<C[i]){
      ans=0;
      break;
    }
    ans*=min(D[i],F[i])-max(C[i],E[i])+1;
    ans%=MOD;
  }
  cout<<ans<<endl;
  }

