#include <bits/stdc++.h>
#include <boost/integer/common_factor_rt.hpp>
using namespace std;
using ll=long long;
const int MOD=1000000007;

int main() {
  ll n,k;
  cin >> n >> k;
  vector<pair<ll,ll>> vp(n);
  for(ll i=0;i<n;i++){
    cin >> vp.at(i).first >> vp.at(i).second;
  }
  sort(vp.begin(),vp.end());
  ll sum=0;
  for(ll i=0;i<n;i++){
    sum+=vp.at(i).second;
    if(sum>=k){
      cout << vp.at(i).first << endl;
      return 0;
    }
  }
}