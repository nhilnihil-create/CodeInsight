#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll n, a, cnt = 0;
  cin >> n;

  map<ll, ll> mp;
  rep(i, n) {
    cin >> a;
    if ((a / 400) >= 8) {
      cnt++;
    } else {
      mp[a / 400]++;
    }
  }

  // for (auto x : mp) cerr << x.first << ' ' << x.second << endl;

  cout << max(int(mp.size()), 1) << ' ' << mp.size() + cnt << endl;

  return 0;
}
