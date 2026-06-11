#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
  string s;
  cin >> s;
  ll ans = 0;
  for (int bit = 0; bit < (1 << s.size()); bit++) {
    ll x = 0;
    for (int i = 0; i < s.size(); i++) {
      if (bit & (1 << i))
        x = x * 10 + (s[i] - '0');
      else {
        ans += x;
        x = 0;
      }
    }
    ans += x;
  }
  cout << ans << endl;
  return 0;
}