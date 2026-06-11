#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  ll n;
  cin >> n;
  vector<ll> a(n);
  map<ll,ll> mp;
  rep(i,n){
    cin >> a.at(i);
    mp[a.at(i)]++;
  }
  ll ans=0;
  for(auto p: mp){
    ans+=(p.second)%2;
  }
  cout << ans;
}