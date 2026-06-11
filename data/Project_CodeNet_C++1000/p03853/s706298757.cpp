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
  ll h,w;
  cin >> h >> w;
  vector<string> c(h);
  for(ll i=0;i<h;i++) cin >> c[i];
  for(ll i=0;i<2*h;i++) {
    cout << c[i/2] << endl;
  }
}