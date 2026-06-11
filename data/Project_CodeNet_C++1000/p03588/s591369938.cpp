#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=1LL<<61;

int main() {
  ll n;
  cin >> n;
  vector<pll> c(n);
  for(ll i=0;i<n;i++) {
    ll a,b;
    cin >> a >> b;
    c[i]={a,b};
  }
  sort(c.rbegin(),c.rend());
  cout << c[0].first+c[0].second << endl;
}