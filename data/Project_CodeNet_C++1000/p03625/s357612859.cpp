#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<string,int>;
const double PI = acos(-1);

int main() {
  ll n;
  cin >> n;
  map<ll,ll> mp;
  rep(i,n){
    ll a;
    cin >> a;
    mp[a]++;
  } 
  vector<ll> a;
  for(auto itr = mp.begin(); itr != mp.end(); itr++){
    if(itr->second > 1) a.push_back(itr->first);
  }
  sort(a.begin(),a.end());
  reverse(a.begin(),a.end());
  if(a.size() == 0 || (a.size() == 1 && mp[a.at(0)] < 4)){
    cout << 0 << endl;
    return 0;
  }
  else{
    ll ans;
    if(mp[a.at(0)] >= 4) ans = a.at(0)*a.at(0);
    else ans = a.at(0)*a.at(1);
    cout << ans << endl;
  }
  
  
}