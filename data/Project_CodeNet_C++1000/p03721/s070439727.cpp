#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  ll n,k;
  cin >> n >> k;
  vector<pair<ll,ll>> vec;
  rep(i,n){
    ll x,y;
    cin >> x >> y;
    vec.push_back(make_pair(x,y));
  }
  sort(vec.begin(),vec.end());
  ll now=0;
  rep(i,n){
    now+=vec[i].second;
    if(k<=now) {
      cout << vec[i].first << endl;
      break;
    }
  }
    
}
