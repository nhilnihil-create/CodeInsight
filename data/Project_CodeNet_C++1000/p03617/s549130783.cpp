#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll q,h,s,d,n;
  cin >>q>>h>>s>>d>>n;
  n*=100;
  P Q = make_pair(q * 8,25), H = make_pair(h * 4,50), S = make_pair(s * 2,100), D = make_pair(d * 1,200);
  vector<P> t = {Q,H,S,D};
  sort(t.begin(),t.end());
  int i = 0;
  ll ans = 0;
  while(n > 0 || i < 4) {
    ll saizu = t[i].second;
    ll kakaku = t[i].first / (200 / saizu);
    ll kosuu = n / saizu;
    n -= kosuu * saizu;
    ans += kosuu * kakaku;
    i++;
  }
  cout << ans << endl;
  return 0;
}