#include <bits/stdc++.h>
using namespace std;
using ll=long long;
/*
これどんな木つくってもおなじ？
ただの範囲の和として確認か
*/
int main(){
  ll N,M; cin>>N>>M;
  vector<ll> A(N+1,0),B(N+1,0);
  for(ll i=0; i<M; i++){
    ll a,b; cin>>a>>b;
    if(a>b) swap(a,b);
    B[a]++;
    B[b]--;
  }
  for(ll i=1; i<N; i++) B[i+1]+=B[i];
  for(ll i=1; i<N; i++){
    if(B[i]%2>0){
      cout<<"NO"<<endl;
      return 0;
    }
  }
  cout<<"YES"<<endl;
}