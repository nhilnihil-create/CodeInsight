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
  ll w,h;
  cin >> w >> h;
  vector<pll> a;
  for(ll i=0;i<w+h;i++) {
    ll tmp;
    cin >> tmp;
    a.push_back(pll(tmp,i<w));
  }
  sort(a.begin(),a.end());
  ll ans=0;
  w++,h++;
  for(auto t:a) {
    if(t.second) {
      ans+=t.first*h;
      w--;
    }
    else {
      ans+=t.first*w;
      h--;
    }
  }
  cout << ans << endl;
}