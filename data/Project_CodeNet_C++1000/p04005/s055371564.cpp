#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

int main() {
  vector<ll> v(3);
  rep(i, 3)
  cin >> v.at(i);
  sort(v.begin(),v.end());
  ll a,b,c;
  a = v.at(0);
  b = v.at(1);
  c = v.at(2);
  
  if(a%2==0 || b%2==0 || c%2==0)
    cout << 0 << endl;
  else
    cout << (a*b*(1+c/2))-(a*b*(c/2)) << endl;
}