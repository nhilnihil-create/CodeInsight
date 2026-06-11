#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0;i<n;i++)
using ll = long long;
using P = pair<ll,ll>;

int main(){
  ll n,t;
  cin>>n>>t;
  vector<ll> v(n);
  rep(i,n) cin>>v.at(i);
  ll sum = 0;
  rep(i,n-1){
    if (v.at(i+1)-v.at(i) >= t){
      sum+=t;
    }
    else {
      sum = sum+(v.at(i+1)-v.at(i));
    }
  }
  sum+=t;
  cout << sum << endl;
}