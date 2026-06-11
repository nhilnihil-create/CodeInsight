#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

const int mod = 1e9 + 7;

// binary exponentiation O(log n)
ll mod_pow(int x, int y) {
  ll res = 1;
  while (y > 0) {
    if (y & 1) res = res * x % mod;  // if right-most bit is 1
    x = x * x % mod;
    y >>= 1;  // right shift y by 1 bit
  }
  return res;
}

int main() {
  int n;
  cin >> n;
  map<int, int> diffs;
  rep(i, n) {
    int pos;
    cin >> pos;
    diffs[pos]++;
  }

  for (int i = (n%2==0); i < n; i++) {
    if (i == 0) {
      if (diffs[i] > 1) {
        cout << 0 << endl;
        return 0;
      }
    }
    else if (diffs[i] > 2) {
      cout << 0 << endl;
      return 0;
    }
  }

  ll ans = 1;
  rep(i, n/2) {
    ans = (ans * 2) % mod;
  }
  cout << ans << endl;
}