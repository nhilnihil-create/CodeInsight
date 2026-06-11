#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;

int main() {
  string s;
  cin >> s;
  ll sum = 0;
  for (int bit = 0; bit < (1 << (s.size() - 1)); bit++) {
    vector<int> v;
    int pre = -1;
    rep(i, s.size() - 1) {
      if (bit & (1 << i)) {
        sum += stoll(s.substr(pre + 1, i - pre));
        pre = i;
      }
    }
    sum += stoll(s.substr(pre + 1, s.size() - 1 - pre));
  }

  cout << sum << endl;
  return 0;
}