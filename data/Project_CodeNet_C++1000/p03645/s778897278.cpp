#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  ll N, M; cin>>N>>M;
  map<ll, ll> X;
  map<ll, ll> Y;
  for(int i=0; i<M; i++){
    ll A, B; cin>>A>>B;
    if(A==1) X[B]=1;
    if(B==N) Y[A]=1;
  }
  bool ikeru=0;
  for(auto p:X){
    auto k=p.first;
    if(Y.count(k)) ikeru=1; 
  }
  if(ikeru) cout<<"POSSIBLE"<<endl;
  else cout<<"IMPOSSIBLE"<<endl;
}
