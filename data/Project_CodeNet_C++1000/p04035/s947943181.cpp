#include <bits/stdc++.h>
using namespace std;
using ll=long long;
/*
ほどくとして端からかな
どこか2本がL以上ならいけるか
*/
int main(){
  ll N,L; cin>>N>>L;
  vector<ll> A(N+1,0);
  for(ll i=1; i<=N; i++) cin>>A[i];
  for(ll i=1; i<N; i++){
    ll n=A[i]+A[i+1];
    if(n>=L){
      ll asz=A.size()-1;
      //頭から
      cout<<"Possible"<<endl;
      for(ll j=1; j<i; j++) cout<<j<<endl;
      for(ll j=asz-1; j>=i; j--) cout<<j<<endl;      
      return 0;
    }
  }
  cout<<"Impossible"<<endl;
}