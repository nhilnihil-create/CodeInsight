#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
const ll INF = 4e18;
const ll MOD = 1e9+7;

typedef pair<ll,ll> P;

int main(){
//  ios::sync_with_stdio(false);
//  cin.tie(0);

  ll w, h;
  cin >> w >> h;
  priority_queue<P,vector<P>,greater<P>> pq;
  for (int i = 0; i < w; i++) {
    ll x;
    cin >> x;
    pq.push(P(x,0));
  }
  for (int i = 0; i < h; i++) {
    ll x;
    cin >> x;
    pq.push(P(x,1));
  }

  ll a[2] = {h+1LL,w+1LL};
  ll ans = 0;
  while (!pq.empty()) {
    P tp = pq.top();
    pq.pop();
    ans += tp.first * a[tp.second];
    a[!tp.second]--;
  }
  cout << ans << endl;
  return 0;
}
