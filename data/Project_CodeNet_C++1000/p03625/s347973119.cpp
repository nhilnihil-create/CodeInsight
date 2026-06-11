#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main(void) {
  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) {
    cin >> a[i];
  }

  map<ll, int> m;
  rep(i, n) {
    m[a[i]]++;
  }

  pair<ll, int>  e1 = make_pair(0, 0);
  pair<ll, int>  e2 = make_pair(0, 0);
  for (auto x: m) {
    if (x.second < 2) continue;
    if (x.first > e1.first) {
      e2.first = e1.first;
      e2.second = e1.second;
      e1.first = x.first;
      e1.second = x.second;
    } else if (x.first > e2.first) {
      e2.first = x.first;
      e2.second = x.second;
    }
  }

  ll ans = 0;
  if (e1.second >= 4) {
    ans = e1.first * e1.first;
  } else {
    ans = e1.first * e2.first;
  }

  cout << ans << endl;
  
  return 0;
}