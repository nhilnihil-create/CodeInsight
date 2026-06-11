#include <algorithm>
#include <bitset>
#include <cmath>
#include <iostream>
#include <limits>
#include <numeric>
#include <string>
#include <vector>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
using namespace std;

int main() {
  string s;
  cin >> s;
  int n = s.size();
  vector<int> a;
  rep(i, n) {
    a.push_back(s[i] - '0');  // cast(char->int)
  }
  ll ans = 0;
  rep(bit, 1 << (n - 1)) {
    ll now = a[0];
    rep(i, n - 1) {
      if (bit & 1 << i) {
        ans += now;
        now = 0;
      }
      now = now * 10 + a[i + 1];
    }
    ans += now;
  }
  cout << ans << endl;
}