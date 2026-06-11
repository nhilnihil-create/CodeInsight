#include <bits/stdc++.h>
#define ll long long
using namespace std;

void Csum(vector<ll> &x){
  for(int i=0;i<x.size()-1;i++){
      x[i+1]+=x[i];
  }
  return ;
}


int main() {
  ll N;
  cin>>N;
  vector<ll> big(N);
  for(ll i=0;i<N;i++){
    cin>>big[i];
  }
  sort(big.begin(),big.end());
  Csum(big);
  ll cnt=1;
  for(int i=1;i<N;i++){
    if(big[i-1]*3>=big[i]){
      cnt++;
    }
    else{
      cnt=1;
    }
    
    if(i==N-1){
      cout<<cnt;
    }
  }
}