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
  string o,e;
  cin >> o >> e;
  for(ll i=0;i<o.size()+e.size();i++) {
    if(i%2) cout << e[i/2];
    else cout << o[i/2];
  }
  cout << endl;
}