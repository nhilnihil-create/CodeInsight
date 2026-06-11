#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<=n;i++)
const ll MOD=1000000007;
const long double PI=3.14159265358979;
const ll MAX=0;

int main() {
  ll N,M,c=0,K;
  cin>>N>>M>>K;
  for(int i=0;i<=N;i++){
    if(M*i==K){
      c=1;
    }
  }
  rep(i,M){
    if(N*i==K){
      c=1;
    }
  }
  rep(i,N){
    rep(j,M){
      if(i*j+(N-i)*(M-j)==K||i*j+(N-i)*(M-j)==N*M-K){
        c=1;
      }
    }
  }
  if(c){
    cout<<"Yes";
  }
  else{
    cout<<"No";
  }
}