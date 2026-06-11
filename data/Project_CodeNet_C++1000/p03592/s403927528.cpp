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
  ll h,w,k;
  cin >> h >> w >> k;
  for(ll i=0;i<=h;i++) {
    for(ll j=0;j<=w;j++) {
      if(i*j+(h-i)*(w-j)==k||i*j+(h-i)*(w-j)==h*w-k) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
}