#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  string s;
  cin >> s;
  ll ans = 0, size = s.length();
  for (int i = 0; i < (1 << (size - 1)); i++) {
    bitset<10> b(i);
    ll m = 1;
    for (int j = 0; j < s.length(); j++) {
      ans += (s[s.length() - j - 1] - '0') * m;
      if (b.test(j) == 0)
        m *= 10;
      else
        m = 1;
    }
  }
  cout << ans << endl;
}
