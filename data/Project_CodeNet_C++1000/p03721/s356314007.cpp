#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
using pll = pair<long long int,long long int>;
#define rep(i,n) for(ll i=0; i<(ll)(n); i++)

int main() {
  ll n,k; cin>>n>>k;
  vector<pll> v(1+100000);
  rep(i,100001){
    v[i].first=i;
    v[i].second=0;
  }
  rep(i,n){
    int a,b; cin>>a>>b;
    v[a].second+=b;
  }
  ll sum=0,i=0;
  while(true){
    sum+=v[i].second;
    if(sum>=k){cout<<v[i].first;break;}
    i++;
  }
}

