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
  string s,t;
  ll q;
  cin >> s >> t >> q;
  vec ss(s.size()+1);
  vec st(t.size()+1);
  for(ll i=0;i<s.size();i++) {
    ss[i+1]=ss[i]+(s[i]=='A');
  }
  for(ll i=0;i<t.size();i++) {
    st[i+1]=st[i]+(t[i]=='A');
  }
  while(q--) {
    ll a,b,c,d;
    cin >> a >> b >> c >> d;
    ll ns=ss[b]-ss[a-1];
    ns=(ns%3+2*(b-a+1-ns)%3)%3;
    ll nt=st[d]-st[c-1];
    nt=(nt%3+2*(d-c+1-nt)%3)%3;
    if(ns==nt) {
      cout << "YES" << endl;
    }
    else {
      cout << "NO" << endl;
    }
  }
}