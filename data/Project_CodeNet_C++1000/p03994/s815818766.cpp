#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  string s;
  ll k;
  cin >> s >> k;
  // cerr << s << " " << k << endl;

  rep(i, s.size()) {
    if (s[i] == 'a') continue;
    int cost = 'z' + 1 - s[i];
    if (cost <= k) {
      s[i] = 'a';
      k -= cost;
    }
    // cerr << s << " " << k << endl;
  }
  if (k > 0) s[s.size() - 1] = (s[s.size() - 1] - 'a' + k) % 26 + 'a';

  cout << s << endl;
  return 0;
}
