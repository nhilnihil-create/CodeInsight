#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
using pii = pair<int, int>;
#define rep(i,n) for(int i=0; i<(int)(n); i++)

int main() {
  ll n; cin>>n;
  vector<ll> v(n);

  rep(i,n){cin>>v[i];}
  if(n%2==0){
    ll m=n/2;
    rep(i,m){cout<<v[2*(m-i)-1]<<" ";}
    rep(i,m){cout<<v[2*i]<<" ";}
  }
  else{
    ll m=(n-1)/2;
    rep(i,m+1){cout<<v[2*(m-i)]<<" ";}
    rep(i,m){cout<<v[2*i+1]<<" ";}
  }
} 