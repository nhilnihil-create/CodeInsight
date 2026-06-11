#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define MOD 1000000007

ll gcd(ll A,ll B){
  while(A%B!=0){
    ll tmp=A%B;
    A=B;
    B=tmp;
  }
  return B;
}

int main(){
  ll N,K;
  cin>>N>>K;
  vector<ll> A(N);
  for(int i=0;i<N;i++){
    cin>>A.at(i);
  }
  sort(A.begin(),A.end());

  ll x=A.at(0);
  for(int i=0;i<N;i++){
    x=gcd(x,A.at(i));
  }

  if(K%x==0&&K<=A.at(N-1)){
    cout<<"POSSIBLE"<<endl;
  }else{
    cout<<"IMPOSSIBLE"<<endl;
  }
}
