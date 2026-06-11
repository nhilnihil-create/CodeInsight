#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  ll N,M,a,b,c; cin>>N>>M;
  vector<ll> A(M+1),B(M+1),C(M+1),D(N+1,-1e15);
  D[1]=0;
  for(int i=1; i<=M; i++){
    cin>>a>>b>>c;
    A[i]=a; B[i]=b; C[i]=c;
  }
  for(int i=1; i<=N-1; i++){
    for(int j=1; j<=M; j++){
      if(D[A[j]]==-1e15) continue;
      else if(D[B[j]]<D[A[j]]+C[j]) D[B[j]]=D[A[j]]+C[j];
    }
  }
  vector<bool> E(N+1,false);
  for(int i=1; i<=N; i++){
    for(int j=1; j<=M; j++){
      if(D[B[j]]<D[A[j]]+C[j]){
        D[B[j]]=D[A[j]]+C[j];
        E[A[j]]=true, E[B[j]]=true;
      }
    }
  }
  if(E[N]) cout<<"inf"<<endl;
  else cout<<D[N]<<endl;
}