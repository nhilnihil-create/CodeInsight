#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

const int mod = 1e9 + 7;

vector<int> decode(string s1, string s2) {
  vector<int> v;
  int i = 0;
  while (i < s1.size()) {
    if (s1[i] == s2[i])
      v.push_back(0), i += 1;
    if (i + 1 < s1.size() && s1[i] == s1[i + 1])
      v.push_back(1), i += 2;
  }
  return v;
}

int main() {
  int N;
  cin >> N;
  string s1, s2;
  cin >> s1 >> s2;

  auto v = decode(s1, s2);

  ll ans = 1;
  rep(i, v.size()) {
    if (i == 0) {
      ans *= v[i] == 0 ? 3 : 6;
    } else {
      int p = v[i - 1], n = v[i];
      if (p == 0 && n == 0)
        ans *= 2;
      if (p == 0 && n == 1)
        ans *= 2;
      if (p == 1 && n == 0)
        ans *= 1;
      if (p == 1 && n == 1)
        ans *= 3;
    }
    ans %= mod;
  }

  cout << ans << endl;
}