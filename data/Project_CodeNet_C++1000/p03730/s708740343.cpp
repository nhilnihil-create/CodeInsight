#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll a, b, c;
  cin >> a >> b >> c;
  map<ll, ll> mp;

  ll i = 1;
  while (mp[(a * i) % b] == 0) {
    mp[(a * i) % b]++;
    if ((a * i) % b == c) {
      cout << "YES" << endl;
      return 0;
    }
    i++;
  }
  cout << "NO" << endl;
  return 0;
}
