#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll a,b,c; cin >> a >> b >> c;
  ll ans = 0;
  if (a%2 == 0 || b%2 == 0 || c%2 == 0) ans = 0;
  else {
    vector<ll> v = {a,b,c};
    sort(v.begin(), v.end());
    ans = abs(((v[2]/2) - (v[2]+1)/2)) * v[0] * v[1];
  }
  cout << ans << endl;
  return 0;
}