#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

int main() {
  ll n,m;
  cin >> n >> m;
  map<ll,ll> a;
  for(ll i=0;i<m;i++) {
    ll x,y;
    cin >> x >> y;
    a[x]++;
    a[y]++;
  }
  for(auto p:a) {
    if(p.second%2) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
}