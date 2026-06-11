#include <bits/stdc++.h>
#include <functional>

using namespace std;
using ll = long long;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;
  map<ll, int> cnts;
  for (int i = 0; i < n; ++i) {
    ll a;
    cin >> a;
    cnts[a]++;
  }

  vector<ll> va;
  for (auto it = cnts.begin(); it != cnts.end(); it++) {
    if (it->second >= 4) {
      va.push_back(it->first);
      va.push_back(it->first);
    } else if (it->second >= 2) {
      va.push_back(it->first);
    }
  }

  sort(va.begin(), va.end(), greater<ll>());
  if (va.size() < 2) {
    cout << 0 << '\n';
  } else {
    cout << va[0] * va[1] << '\n';
  }

  return 0;
}