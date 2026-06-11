#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

int main() {
  string s;
  cin >> s;
  map<char,ll> temp;
  for(ll i=0;i<s.size();i++) {
    temp[s[i]]++;
  }
  ll ans=s.size()*(s.size()-1)/2+1;
  for(auto p:temp) {
    ll n=p.second;
    ans-=n*(n-1)/2;
  }
  cout << ans << endl;
}