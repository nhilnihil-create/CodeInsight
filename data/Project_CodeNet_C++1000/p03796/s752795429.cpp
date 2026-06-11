#include<iostream>
using namespace std;
using ll=long long;
const ll mod=1000000007;
int main(){

  ll N;
  cin>>N;
  ll power=1;
  for(int i=1;i<=N;i++){
  
    power*=i;
    power%=mod;
  }
  cout<<power;
  return 0;
}