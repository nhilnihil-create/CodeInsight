#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  vector<int> A(n);
  map<int, int> hsh;
  for (auto &a : A) {
    cin >> a;
    hsh[a]++;
  }
  if (n%2 == 0) {
    for (auto &h : hsh) {
      if (h.first%2 == 0 || h.second != 2) {
        cout << 0 << endl;
        return 0;
      }
    }
  } else {
    for (auto &h : hsh) {
      if (h.first%2 == 1 || (h.first != 0 && h.second != 2)) {
        cout << 0 << endl;
        return 0;
      }
    }
  }
  long long res = 1;
  int mod = 1e9+7;
  for (int i = 0; i < n/2; ++i) {
    res = (res * 2)%mod;
  }
  cout << res << endl;

  return 0;
}

