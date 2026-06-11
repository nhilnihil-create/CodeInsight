#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i<n;i++)
using ll = long long;
using P = pair<ll,ll>;

int main() {
  ll n;cin>>n;
  vector<ll> v(n);
  rep(i,n) cin>>v.at(i);
  ll sum4 = 0,sum2 = 0;
  rep(i,n){
    if (v.at(i) % 4 == 0){
      sum4++;
    }
  }
  if (sum4*2 + 1 >= n){
    cout << "Yes" << endl;
    return 0;
  }
  else {
    rep(i,n){
      if (v.at(i) % 2 == 0){
        sum2++;
      }
    }
    if (sum4*2 + (sum2 - sum4) >= n){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}