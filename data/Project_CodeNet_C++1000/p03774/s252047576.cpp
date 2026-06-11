#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
using P = pair<ll, ll>;

int main() {
  ll n,m;
  cin >> n >> m;
  vector<P> gakusei(n), check(m);
  rep(i,n) {
    ll a,b;
    cin >> a >> b;
    gakusei[i].first = a;
    gakusei[i].second = b;
  }
  rep(i,m) {
    ll c,d;
    cin >> c >> d;
    check[i].first = c;
    check[i].second = d;
  }
  ll ans = 1e10;
  int cnt;
  rep(i,n)rep(j,m) {
    ll tmp;
    tmp = abs(gakusei[i].first-check[j].first) + abs(gakusei[i].second-check[j].second);
    if (tmp < ans) {
      ans = tmp;
      cnt = j;
    }
    if (j == m-1) {
      cnt++;
      cout << cnt << endl;
      ans = 1e10;
      cnt = 0;
    }
  }
  return 0;
}