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
  vector<string> s(3);
  for(ll i=0;i<3;i++) cin >> s[i];
  ll f=1;
  for(ll i=0;i<2;i++) {
    if (s[i][s[i].size()-1]!=s[i+1][0]) f=0;
  }
  if(f) cout << "YES" << endl;
  else cout << "NO" << endl;
}