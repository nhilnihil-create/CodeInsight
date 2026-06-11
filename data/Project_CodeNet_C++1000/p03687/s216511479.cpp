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
  string s;
  cin >> s;
  map<char,ll> count;
  ll mx=inf;
  for(ll i=0;i<'z'-'a'+1;i++) {
    ll temp=-1;
    ll tx=0;
    for(ll j=0;j<s.size();j++) {
      if(s[j]=='a'+i) {
        tx=max(tx,j-temp-1);
        temp=j;
      }
    }
    tx=max(tx,(ll)s.size()-temp-1);
    mx=min(tx,mx);
  }
  cout << mx << endl;
}