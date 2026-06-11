#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=5e18;

int main() {
  ll n,s,g,l,h;
  cin >> n >> s >> g >> l >> h;
  for(ll i=0;i<n;i++) {
    if(l*(n-1-i)-h*i<=g-s&&g-s<=-l*i+h*(n-1-i)) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
}