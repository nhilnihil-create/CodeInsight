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
  rep(i,0,N) B[A[i]-1]=i;
  vi C(N),D(N);
  C[0]=1;
  D[0]=1000000000;
  rep(i,1,N){
    if(B[i]<B[i-1]){
      C[i]=C[i-1]+1;
      D[i]=C[i-1]+D[i-1]+B[i]-B[i-1]-C[i];
    }
    else{
      D[i]=D[i-1]-1;
      C[i]=C[i-1]+D[i-1]+B[i]-B[i-1]-D[i];
    }
  }
  rep(i,0,N) cout<<C[i]<<" ";
  cout<<endl;
  rep(i,0,N) cout<<D[i]<<" ";
  cout<<endl;
  }

