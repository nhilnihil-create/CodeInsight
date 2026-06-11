#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  ll n,m;cin>>n>>m;

  map<int, int>log;
  rep(i,2*m){
    int t;cin>>t;
    log[t]++;
  }

  bool f=true;
  for(auto p:log){
    if(p.second%2){
      f=false;
      break;
    }
  }
  cout<<(f?"YES":"NO");

  return 0;
}