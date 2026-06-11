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
  string S,T; cin>>S>>T;
  int N=S.size(),M=T.size();
  vi A(N+1),B(N+1),C(M+1),D(M+1);
  rep(i,0,N){
    A[i+1]=A[i];
    B[i+1]=B[i];
    if(S[i]=='A') A[i+1]++;
    else B[i+1]++;
  }
  rep(i,0,M){
    C[i+1]=C[i];
    D[i+1]=D[i];
    if(T[i]=='A') C[i+1]++;
    else D[i+1]++;
  }
  int Q; cin>>Q;
  rep(i,0,Q){
    int p,q,r,s; cin>>p>>q>>r>>s;
    int E=A[q]-A[p-1],F=B[q]-B[p-1],G=C[s]-C[r-1],H=D[s]-D[r-1];
    E%=3;
    F%=3;
    G%=3;
    H%=3;
    if((E+3-G)%3==(F+3-H)%3) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }
  }

