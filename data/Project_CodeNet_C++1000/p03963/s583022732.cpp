#include<iostream>
using namespace std;
using ll=long long;
int main(){

  ll N,K;
  cin>>N>>K;
  ll ans=K;
  for(ll i=1;i<=N-1;i++){
  
    ans*=K-1;
  }
  cout<<ans;
  return 0;
}